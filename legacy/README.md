###Alpha Synapse

**Requirements:** None  
**Limitations:** None  

![EDIT THIS LINK](http://www.rtxi.org/wp-content/uploads/2011/04/alphasyn.png)

This module creates an artificial synapse where the fixed conductance change is described by an alpha function. The fixed conductance waveform is pre-computed according to: 

The current is computed according to Ohm's Law:

This conductance is triggered by an event indicated by a value of “1″ on input(1). This can be used to generate a spike-triggered synaptic connection using the [Spike Detector module](https://github.com/RTXI/spike-detector).

####Input Channels
1. input(0) – “Vm” : Membrane potential
2. input(1) – “Spike State” : Spike State (=1 to trigger synapse)

####Output Channels
1. output(0) – “Isyn” : Output current (A)

####Parameters
1. Gmax (nS) : Maximum synaptic conductance for stimulus
2. Time Constant tau (ms) : Time constant for alpha-shaped conductance
3. Esyn (mV) : Reversal potential for conductance