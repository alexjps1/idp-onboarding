"use client"

import * as React from "react"
import { useRouter } from "next/navigation"
import { ArrowRight, Car, Check, ClipboardList, RotateCcw, X } from "lucide-react"

import { cn } from "@/lib/utils"
import { getAdjacentSteps } from "@/lib/study-steps"
import { QUIZ_QUESTIONS, type QuizQuestion } from "@/lib/quiz-questions"
import { useStudy } from "@/components/study/study-provider"
import { StudyShell } from "@/components/study/study-shell"
import { StudyFooter } from "@/components/study/study-footer"
import { Progress } from "@/components/ui/progress"

type Phase = "answering" | "feedback"

/**
 * Post-onboarding knowledge check. Like the legacy prototype, questions are
 * answered one at a time and a wrong answer is *not* revealed — instead the
 * question is sent to the back of the queue and asked again later, so the
 * participant keeps going until every question has been answered correctly. The
 * question area scrolls internally so long questions never clip on the tablet.
 */
export default function QuizPage() {
  const router = useRouter()
  const { mode, adaptedModules, startQuiz, recordQuizAnswer, finishQuiz } =
    useStudy()
  const { next } = getAdjacentSteps("quiz", mode)

  // Only quiz the modules the guide actually showed: skip questions whose module
  // was omitted during adaptation (mirrors the legacy "only visible categories"
  // behaviour). Baseline (adaptedModules === null) keeps every module. alwaysKeep
  // modules never appear in adaptedModules, so they are always included.
  const initialQuestions = React.useMemo(() => {
    const omitted = new Set(
      (adaptedModules ?? []).filter((s) => s.omitted).map((s) => s.id)
    )
    return QUIZ_QUESTIONS.filter((q) => !omitted.has(q.category))
  }, [adaptedModules])

  const totalUnique = initialQuestions.length

  // Remaining questions to get right. A wrong answer rotates its question to the
  // back; a correct answer removes it. The quiz ends when the queue is empty.
  const [queue, setQueue] = React.useState<QuizQuestion[]>(
    () => initialQuestions
  )
  const [selected, setSelected] = React.useState<number | null>(null)
  const [phase, setPhase] = React.useState<Phase>("answering")

  const question = queue[0]
  const answering = phase === "answering"
  const isCorrect =
    selected !== null && question?.options[selected]?.correct === true
  const solved = totalUnique - queue.length

  // Stamp the quiz start time once, on first mount of a run.
  const started = React.useRef(false)
  React.useEffect(() => {
    if (started.current) return
    started.current = true
    startQuiz()
  }, [startQuiz])

  function confirm() {
    if (selected === null || !question) return
    recordQuizAnswer({
      category: question.category,
      // Record the stable index into the full QUIZ_QUESTIONS list, not the
      // filtered position, so answers stay comparable across participants.
      questionIndex: QUIZ_QUESTIONS.indexOf(question),
      selectedIndex: selected,
      correct: question.options[selected].correct,
    })
    setPhase("feedback")
  }

  function advance() {
    if (isCorrect) {
      const rest = queue.slice(1)
      if (rest.length === 0) {
        finishQuiz()
        if (next) router.push(next.path)
        return
      }
      setQueue(rest)
    } else {
      // Wrong: send this question to the back of the queue to ask it again later.
      setQueue([...queue.slice(1), queue[0]])
    }
    setSelected(null)
    setPhase("answering")
  }

  // Once the queue empties we navigate away; render nothing during that tick.
  if (!question) return null

  // Answering the last remaining question correctly ends the quiz and continues
  // to the next study step (the drive, or the final screen).
  const finishing = isCorrect && queue.length === 1
  const toDrive = next?.slug === "drive"

  return (
    <StudyShell
      footer={
        answering ? (
          <StudyFooter
            nextLabel="Bestätigen"
            nextIcon={<Check />}
            onNext={confirm}
            nextDisabled={selected === null}
          />
        ) : (
          <StudyFooter
            nextLabel={
              finishing ? (toDrive ? "Zur Fahrt wechseln" : "Zum Abschluss") : "Weiter"
            }
            nextIcon={finishing && toDrive ? <Car /> : <ArrowRight />}
            onNext={advance}
          />
        )
      }
    >
      <div className="mx-auto flex h-full w-full max-w-3xl flex-col">
        {/* Progress header */}
        <header className="mb-6 shrink-0 space-y-3">
          <div className="flex items-center justify-between gap-4">
            <span className="text-sm font-semibold uppercase tracking-wide text-primary">
              {question.categoryName}
            </span>
            <span className="text-lg tabular-nums text-muted-foreground">
              Noch {queue.length} {queue.length === 1 ? "Frage" : "Fragen"}
            </span>
          </div>
          <Progress value={totalUnique > 0 ? (solved / totalUnique) * 100 : 0} />
        </header>

        {/* Question + options (scrolls if it would otherwise clip) */}
        <div className="min-h-0 flex-1 overflow-y-auto pb-2">
          <h1 className="text-3xl font-bold leading-snug tracking-tight text-foreground">
            {question.question}
          </h1>

          <div className="mt-8 flex flex-col gap-3">
            {question.options.map((option, i) => {
              const chosen = selected === i
              // Only ever colour the chosen option — a wrong answer never
              // reveals which option was correct.
              const showCorrect = !answering && chosen && option.correct
              const showWrong = !answering && chosen && !option.correct

              return (
                <button
                  key={option.text}
                  type="button"
                  disabled={!answering}
                  onClick={() => setSelected(i)}
                  className={cn(
                    "flex items-center gap-4 rounded-xl border-2 px-5 py-4 text-left text-xl transition-colors",
                    showCorrect
                      ? "border-emerald-500 bg-emerald-500/10 text-foreground"
                      : showWrong
                        ? "border-destructive bg-destructive/10 text-foreground"
                        : chosen && answering
                          ? "border-primary bg-primary/5"
                          : answering
                            ? "border-border hover:border-primary/40 hover:bg-accent"
                            : "border-border opacity-60"
                  )}
                >
                  <span
                    className={cn(
                      "flex size-7 shrink-0 items-center justify-center rounded-full border-2 transition-colors",
                      showCorrect
                        ? "border-emerald-500 bg-emerald-500 text-white"
                        : showWrong
                          ? "border-destructive bg-destructive text-white"
                          : chosen
                            ? "border-primary bg-primary text-primary-foreground"
                            : "border-muted-foreground/40"
                    )}
                  >
                    {showCorrect ? (
                      <Check className="size-4" />
                    ) : showWrong ? (
                      <X className="size-4" />
                    ) : chosen ? (
                      <span className="size-2.5 rounded-full bg-current" />
                    ) : null}
                  </span>
                  <span className="flex-1">{option.text}</span>
                </button>
              )
            })}
          </div>

          {!answering ? (
            isCorrect ? (
              <p className="mt-6 flex items-center gap-2 text-lg font-medium text-emerald-600">
                <Check className="size-5" /> Richtig!
              </p>
            ) : (
              <p className="mt-6 flex items-center gap-2 text-lg font-medium text-amber-600">
                <RotateCcw className="size-5" /> Leider falsch – diese Frage wird
                später noch einmal gestellt.
              </p>
            )
          ) : null}
        </div>
      </div>

      {/* Decorative step icon in the top-right of the content area */}
      <span className="pointer-events-none fixed right-6 top-4 hidden items-center gap-2 text-muted-foreground sm:flex">
        <ClipboardList className="size-5" />
        <span className="text-sm font-medium">Wissenstest</span>
      </span>
    </StudyShell>
  )
}
