import type { Metadata } from "next"

import "./globals.css"
import { PwaRelauncher } from "@/components/study/pwa-relauncher"
import { StudyProvider } from "@/components/study/study-provider"

export const metadata: Metadata = {
  title: "ResearchMonitor — Onboarding-Studie Fahrassistenz",
  description:
    "Onboarding-Studie zu SAE Level 2 Fahrassistenzsystemen (Human-Factors-Forschung).",
}

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode
}>) {
  return (
    <html lang="de" suppressHydrationWarning>
      <body className="antialiased">
        <StudyProvider>
          <PwaRelauncher />
          {children}
        </StudyProvider>
      </body>
    </html>
  )
}
