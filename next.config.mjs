/** @type {import('next').NextConfig} */
const nextConfig = {
  // Build a self-contained server (.next/standalone) so the app can run on a
  // small server without installing node_modules or building there.
  output: "standalone",
  // The app uses plain <img>, not next/image, so image optimization is never
  // used. Disabling it means the platform-specific `sharp` binary is never
  // loaded at runtime, so a macOS build runs unchanged on the Linux server
  // (the unused sharp files are stripped from the bundle before deploy).
  images: { unoptimized: true },
  // Serve under a subpath (e.g. "/idp-app") when set at build time; kept in
  // sync with BASE_PATH in lib/base-path.ts. Unset → served at the domain root.
  basePath: process.env.NEXT_PUBLIC_BASE_PATH || undefined,
}

export default nextConfig
