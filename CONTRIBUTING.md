# Contributing

## Build (Visual Studio)
1. Install Visual Studio 2022 with the **Desktop development with C++** workload.
2. Open `01-foundations/src/native-inspector/native-inspector.slnx`.
3. Select `x64` and `Debug` or `Release`.
4. Build with `Build > Build Solution`.

## Add a New Lab
1. Create a new markdown file under the appropriate module `labs/` directory.
2. Keep the lab goal, prerequisites, and validation steps clear and short.
3. Add a link from that module's `README.md`.

## Add a New Tool
1. Create a folder under the module `src/` directory.
2. Keep project-local docs close to the tool (short usage/build notes).
3. Add a link from the module `README.md` so it is discoverable.

## Style
- Prefer clear, direct language over formal wording.
- Keep changes focused and small.
- Use relative links in markdown docs.
- Avoid broad refactors in doc-only or structure-only changes.
