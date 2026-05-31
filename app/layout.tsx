import type { Metadata } from "next"
import { Inter, JetBrains_Mono } from "next/font/google"

import "./globals.css"
import { cn } from "@/lib/utils"
import { StudyProvider } from "@/components/study/study-provider"

const inter = Inter({ subsets: ["latin"], variable: "--font-inter" })

const jetbrainsMono = JetBrains_Mono({
  subsets: ["latin"],
  variable: "--font-jetbrains-mono",
})

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
      <body className={cn("antialiased", inter.variable, jetbrainsMono.variable)}>
        <StudyProvider>{children}</StudyProvider>
      </body>
    </html>
  )
}
