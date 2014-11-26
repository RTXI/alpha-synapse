###Alpha Synapse

**Requirements:** None  
**Limitations:** None  

![Alpha Synapse GUI](alpha-synapse.png)


<!--start-->
This module creates an artificial synapse where the fixed conductance change is described by an alpha function. The fixed conductance waveform is pre-computed according to:  

<img src="http://bit.ly/1zWcc5u" align="center" border="0" alt="G=G_{max}*\frac{t}{\tau}*exp(- \frac{t-\tau}{\tau}) " width="236" height="43" />

The current is computed according to Ohm's Law:

<img src="http://bit.ly/1zWcnOg" align="center" border="0" alt="I_{syn}=G*(V_{m}-E_{syn})" width="181" height="21" />

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
