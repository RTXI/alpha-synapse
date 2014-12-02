###Alpha Synapse

**Requirements:** None  
**Limitations:** None  

![Alpha Synapse GUI](alpha-synapse.png)  


<!--start-->  

This module creates an artificial synapse where the fixed conductance change is described by an alpha function. The fixed conductance waveform is pre-computed according to:  

<div style="text-align:center;">G=Gmax\*(t/tau)\*exp(-(t-tau)/tau))</div>

The current is computed according to Ohm's Law:

<div style="text-align:center;">Isyn=G\*(Vm-Esyn)</div>

This conductance is triggered by an event indicated by a value of “1″ on input(1). This can be used to generate a spike-triggered synaptic connection using the [Spike Detector module](https://github.com/RTXI/spike-detector).  

<!--end-->

####Input Channels
1. input(0) – “Vm” : Membrane potential
2. input(1) – “Spike State” : Spike State (=1 to trigger synapse)

####Output Channels
1. output(0) – “Isyn” : Output current (A)

####Parameters
1. Gmax (nS) : Maximum synaptic conductance for stimulus
2. Time Constant tau (ms) : Time constant for alpha-shaped conductance
3. Esyn (mV) : Reversal potential for conductance
