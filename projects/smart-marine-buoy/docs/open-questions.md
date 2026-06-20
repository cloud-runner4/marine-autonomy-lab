# Open questions

Live questions and how each gets resolved. Updated as they close.

1. **Window length & sample rate.** Long enough to resolve sub-0.1 Hz features (tens of seconds)
   vs latency and power. Resolve by sweep in Phases 1–2; document the tradeoff.
2. **MPU6050 noise floor.** Can it resolve single-milli-g heave at sub-Hz? Resolve by a
   static-device PSD at M1 — the gate for the whole sensing chain.
3. **LoRa antenna routing** through the sealed hull: external whip on the gland vs internal with
   loss. Plan by M4, decide at integration.
4. **Synthetic-distribution realism.** Do P-M / JONSWAP-derived spectra match local seas?
   Cross-check against Plymouth Coastal Observatory / CDIP Waverider data before trusting the bins.
5. **Synthetic-to-real gap (core research question).** How well does a model trained on synthetic
   spectra generalise to real heave data from the Cardigan buoy? The thread that makes this more
   than a portfolio piece.
6. **Classical baseline (v2).** Hs from spectral moments, thresholded — build once the ML
   pipeline is validated, then benchmark ML against it (ADR-0007).
7. **Edge Impulse project visibility:** public vs private. Decide before the first model commit.
8. **Still-water site for the free-decay test.** A pond or dock edge gives a clean drop; a
   domestic container risks wall effects — and the site caps maximum hull size. Scout before
   fixing hull dimensions.
