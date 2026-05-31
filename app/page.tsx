import { redirect } from "next/navigation"

// The study always begins at the consent step.
export default function Home() {
  redirect("/consent")
}
