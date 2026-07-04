import type { Metadata } from "next"
import { Geist, Geist_Mono } from "next/font/google"

import "./globals.css"
import { PwaRelauncher } from "@/components/study/pwa-relauncher"
import { StudyProvider } from "@/components/study/study-provider"

// Geist (shadcn's default) is loaded as the fallback for non-Apple devices;
// the SF Pro system stack in globals.css takes precedence on the study iPad.
const geistSans = Geist({ subsets: ["latin"], variable: "--font-geist-sans" })
const geistMono = Geist_Mono({
  subsets: ["latin"],
  variable: "--font-geist-mono",
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
    <html
      lang="de"
      suppressHydrationWarning
      className={`${geistSans.variable} ${geistMono.variable}`}
    >
      <body className="antialiased">
        <StudyProvider>
          <PwaRelauncher />
          {children}
        </StudyProvider>
      </body>
    </html>
  )
}
