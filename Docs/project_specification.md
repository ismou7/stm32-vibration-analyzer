# Project Specification: STM32 Vibration Analyzer

## 1. System Overview
- Microcontroller: STM32 Nucleo F411RE (ARM Cortex-M4 with FPU)
- Sensor: KY-037 Big Microphone Module (using analog output `AO`)
- Measured Physical Quantity: Acoustic vibrations / sound pressure fluctuations (converted to analog voltage 0-3.3V)

## 2. Sampling Parameters
- Maximum Target Frequency (fmax): 500 Hz
- Sampling Frequency (fs): 1000 Hz (1 kHz), satisfying the Nyquist criterion (fs >= 2fmax)
- Block Size(N): 256 samples (chosen as a power of 2 for optimal DFT performance)

## 3. Signal Processing & Filtering
- Digital Filter: FIR Low-Pass Filter to eliminate high-frequency noise.
- Frequency Analysis: Custom Discrete Fourier Transform (DFT) for magnitude extraction.

## 4. Operational States & Fault Detection
- Normal State: Background room noise / ambient sound with low signal amplitude and low RMS.
- Fault / Trigger State: High-amplitude acoustic impact or a dominant frequency peak exceeding defined statistical thresholds.
