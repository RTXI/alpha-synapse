###Alpha Synapse

**Requirements:** None  
**Limitations:** None  

![Alpha Synapse GUI](alpha-synapse.png)  

<!--start-->  

This module creates an artificial synapse where the fixed conductance change is described by an alpha function. The fixed conductance waveform is pre-computed according to:  

<!--end-->

<!--<div style="text-align:center;">G=Gmax\*(t/tau)\*exp(-(t-tau)/tau))</div>-->
<div style="text-align:center"><img src="http://www.sciweavers.org/tex2img.php?eq=G%20%3D%20G_%7Bmax%7D%20%2A%20%20%5Cfrac%7Bt%7D%7B%5Ctau%7D%20%2A%20%20exp%5Cbig%5B%5Cfrac%7B-%28t-%5Ctau%29%7D%7B%5Ctau%7D%5Cbig%5D&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="G = G_{max} *  \frac{t}{\tau} *  exp\big[\frac{-(t-\tau)}{\tau}\big]" width="256" height="43" /></div>

<br>
The current is computed according to Ohm's Law:  

<!--<div style="text-align:center;">Isyn=G\*(Vm-Esyn)</div>-->
<div style="text-align:center"><img src="http://www.sciweavers.org/tex2img.php?eq=I_%7Bsyn%7D%20%3D%20G%20%2A%20%28V_%7Bm%7D%20-%20E_%7Bsyn%7D%29&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="I_{syn} = G * (V_{m} - E_{syn})" width="181" height="21" /></div>

<br>
This conductance is triggered by an event indicated by a value of “1″ on input(1). This can be used to generate a spike-triggered synaptic connection using the [Spike Detector module](https://github.com/RTXI/spike-detector). Use the connector module to connect the spike state output of the spike detector to the sp
ike state input of this one.  

####Input Channels
1. input(0) – “Vm” : Membrane potential (V)
2. input(1) – “Spike State” : Spike State (=1 to trigger synapse)

####Output Channels
1. output(0) – “Isyn” : Output current (A)

####Parameters
1. Gmax : Maximum synaptic conductance for stimulus (nS) 
2. Time Constant tau : Time constant for alpha-shaped conductance (ms) 
3. Esyn : Reversal potential for conductance (mV) 
