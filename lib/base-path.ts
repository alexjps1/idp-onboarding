/**
 * Base path the app is served under (e.g. "/idp-app" when hosted as a subpath
 * behind a reverse proxy, "" at the domain root). Set at build time via
 * NEXT_PUBLIC_BASE_PATH and kept in sync with `basePath` in next.config.mjs.
 *
 * Next automatically prefixes <Link>/router navigations and /_next assets with
 * the configured basePath, but NOT raw URLs like `<img src="/gifs/…">` or
 * `fetch("/api/…")`. Those must go through {@link withBasePath}.
 */
export const BASE_PATH = process.env.NEXT_PUBLIC_BASE_PATH ?? ""

/** Prefix an absolute app path (asset or API route) with the base path. */
export function withBasePath(path: string): string {
  return `${BASE_PATH}${path}`
}
