import { redirect } from "next/navigation"

// The study now begins at the study-mode selection step.
export default function Home() {
  redirect("/mode")
}
