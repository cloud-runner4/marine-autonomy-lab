# Open questions

Live engineering questions, updated as they resolve. Each links to the decision it pressures.

1. **Sensor bandwidth vs fault frequencies.** Does ADXL345's ~1600 Hz usable bandwidth capture
   the bearing harmonics that matter for the target machines, or is the v2 upgrade needed sooner?
   (ADR-0001, ADR-0007)
2. **Present vs incipient bearing detection.** v1 should detect a *seeded* (gross) bearing defect.
   But *early* damage shows first as high-frequency resonance above the v1 band — so how far can
   plain FFT band-energy features go before envelope analysis + more bandwidth are required? This
   is the boundary between what v1 can honestly claim and what is v2. (ADR-0003, ADR-0001)
3. **Pipeline cross-check against public data.** CWRU is recorded at 12/48 kHz on a high-bandwidth
   sensor, so it can't be compared like-for-like. Down-sampled into the v1 band, which fault
   signatures survive, and does the hand-built pipeline recover them? (ADR-0004)
4. **Mounting and coupling.** *(Promoted to a decision — ADR-0009.)* How much do mounting stiffness
   and location change the features, and can a standard mounting spec be defined so models transfer
   between machines? Now a Phase-1 deliverable, not just a question.
5. **Window length vs latency vs resolution.** What FFT window/overlap balances frequency
   resolution at low fault frequencies against responsiveness? (ADR-0007)
6. **Per-class performance honesty.** Imbalance (1× RPM) and looseness (1× harmonics + raised
   floor) are easily separable at this bandwidth, so headline accuracy will look high regardless.
   How is bearing-class performance reported separately so the metric isn't flattered by the easy
   classes? (method / ADR-0003)
7. **Variable speed.** Fixed-RPM assumptions simplify v1; do real machines need order tracking
   (a tachometer reference) for the method to hold? (future)
8. **Envelope analysis.** Would envelope/demodulation features materially improve early bearing
   detection over plain FFT bands? (candidate v2 enhancement, ADR-0003)
9. **Power budget.** What is the duty-cycled power cost of sample-process-sleep, and does it fit
   a realistic subsea energy budget? (deferred to hardware phase)
10. **Selective raw capture.** Should the device retain short raw snippets on anomaly for later
    analysis, despite the comms constraint? (ADR-0005)
