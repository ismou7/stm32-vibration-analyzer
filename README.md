# \# STM32 Real-Time Vibration \& Acoustic Analysis System

# 

# An embedded real-time signal processing system for capturing and filtering vibrations and acoustic signals using an STM32F411RE microcontroller and a KY-037 sensor.

# 

# \---

# 

# \## 1. System Overview \& Hardware

# Microcontroller: STM32 Nucleo Board with STM32F411RE (ARM Cortex-M4 with Hardware FPU)

# Sensor:KY-037 Microphone / Vibration Sensor (using the analog output `AO`)

# Measured Quantity:Acoustic vibrations and sound pressure fluctuations (converted to 0–3.3V analog voltage)

# System Clock Configured at 100 MHz

# 

# \---

# 

# \## 2. Sampling Parameters \& Configuration

# Sampling Frequency (f\_s):1000 Hz (1 kHz), controlled via a Timer 2 Interrupt.

# Block Size (N):256 samples (`FIFOMAXSIZE`), optimized for buffering and block processing.

# Synchronization:Thread-safe data transfer between the interrupt service routine and the main loop via a robust FIFO buffer (`fifo.c`).

# 

# \---

# 

# \## 3. Signal Processing (DSP)

# Filtering:Implementation of an FIR low-pass filter via convolution to attenuate high-frequency noise.

# Floating-Point Acceleration:Utilization of the ARM Cortex-M4 FPU (Floating Point Unit) for high-performance filter calculations.

# Visualization:Live output of raw sensor data and filtered signals via UART (115200 Baud) to a serial plotter.

# 

# \---

# 

# \## 4. Software Architecture \& File Structure

# `main.c` – Main loop, state detection, and coordination of DSP convolution

# `fifo.c / fifo.h` – Ring buffer implementation for decoupled data transfer from the timer interrupt

# `adc.c / adc.h` – Initialization and reading of the analog ADC1 channel

# `tim.c / tim.h` – Configuration of Timer 2 for the precise 1 kHz sampling clock

# `signal.c / signal.h` – Definition of FIR filter coefficients (impulse response)

# `uart.c / uart.h` – UART2 driver for debug and plotter output

# 

# \---

# 

# \## 5. Operational States

# Normal State:Background room noise / ambient vibrations with low signal amplitude and low RMS.

# Trigger State:Detection of impact or vibration events where amplitudes exceed defined statistical thresholds.

