# ADR-0004: Transmit a classification, sized to one satellite frame

- **Status:** Accepted (2026-06-16)
- **Context:** The thesis is bandwidth economy for remote platforms. LoRa was the assumed link, but LoRa is coastal/nearshore (single-digit km over water) and does not represent the offshore problem. The real offshore solution is satellite — Iridium Short-Burst-Data (~340-byte frames, real per-message cost).
- **Options considered:** (a) LoRa as the endpoint; (b) frame LoRa as a prototype for a satellite link and size the payload accordingly; (c) SD-only for v1.
- **Decision:** Payload = class label + confidence + timestamp, sized to fit a single Iridium SBD frame. LoRa (RFM95, 868 MHz) is the bench/coastal prototype for that link and is *in* the MVP — the link must close for the thesis to be demonstrated. SD logging is a de-risking step, not the deliverable.
- **Consequences:** Aligns the motivation with the implementation and shows awareness of the real comms stack. Satellite hardware itself is deferred to v2.
- **Revisit when:** a satellite modem is integrated (v2).
