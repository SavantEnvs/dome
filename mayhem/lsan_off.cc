// Build-time LSan disable hook (sanctioned form — see mayhem/build.sh). embed's main()
// (src/tools/embed-standalone.c) reads the whole input into a malloc'd buffer and never frees it
// before returning, so LSan reports a "leak" on EVERY input, including the seeds — flooding the
// fuzzer with leaks before it can reach a real memory defect. This disables ONLY leak detection;
// ASan's real memory-safety checks (overflow, use-after-free, …) and halting UBSan stay fully on.
extern "C" int __lsan_is_turned_off(void) { return 1; }
