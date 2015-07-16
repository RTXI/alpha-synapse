/*
 Copyright (C) 2011 Georgia Institute of Technology
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 */

#include <alpha-synapse.h>
#include <math.h>

extern "C" Plugin::Object *
createRTXIPlugin(void)
{
  return new alphasyn();
}

static DefaultGUIModel::variable_t vars[] =
  {
    { "Vm", "Membrane potential (V)", DefaultGUIModel::INPUT, },
    { "Spike State", "Spike State (=1 to trigger synapse)",
        DefaultGUIModel::INPUT, },
    { "Isyn", "Output current (A)", DefaultGUIModel::OUTPUT, },
    { "Gmax", "Maximum synaptic conductance for stimulus (nS)",
        DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE, },
    { "Tau", "Time constant for alpha-shaped conductance (ms)",
        DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE, },
    { "Esyn", "Reversal potential for conductance (mV)",
        DefaultGUIModel::PARAMETER | DefaultGUIModel::DOUBLE, },
    { "Time", "Time (s)", DefaultGUIModel::STATE, }, };

static size_t num_vars = sizeof(vars) / sizeof(DefaultGUIModel::variable_t);

alphasyn::alphasyn(void) :
  DefaultGUIModel("Alpha Synapse", ::vars, ::num_vars)
{
  setWhatsThis(
      "<p><b>Alpha Synapse:</b><br>This module creates an alpha-type synapse.</p>");
  createGUI(vars, num_vars);
  initParameters();
  initStimulus();
  update( INIT);
  refresh();
  resizeMe();
}

alphasyn::~alphasyn(void)
{
}

void
alphasyn::execute(void)
{
  systime = count * dt; // time in seconds
  Vm = input(0); // voltage in V

  if (input(1) == 1)
    { // spike just occurred so reset counter to beginning of template conductance
      Gsyncount = 0;
    }
  if (Gsyncount > nsamples)
    output(0) = 0;
  else
    output(0) = arrGsyn[Gsyncount] * (Vm - esyn);
  count++;
  Gsyncount++;
}

void
alphasyn::update(DefaultGUIModel::update_flags_t flag)
{
  switch (flag)
    {
  case INIT:
    setParameter("Gmax (nS)", QString::number(gmax * 1e9)); // initialized in S, display in nS
    setParameter("Time Constant tau (ms)", QString::number(tau * 1e3)); // initialized in s, display in ms
    setParameter("Esyn (mV)", QString::number(esyn * 1e3)); // initialized in V, display in mV
    setState("Time (s)", systime);
    break;
  case MODIFY:
    gmax = getParameter("Gmax (nS)").toDouble() * 1e-9; // set by user in nS, change to S
    tau = getParameter("Time Constant tau (ms)").toDouble() * 1e-3; // set by user in ms, change to s
    esyn = getParameter("Esyn (mV)").toDouble() * 1e-3; // set by user in mV, change to V
    initStimulus();
    break;
  case PERIOD:
    dt = RT::System::getInstance()->getPeriod() * 1e-9; // time in seconds
    initStimulus();
  case PAUSE:
    output(0) = 0.0;
    break;
  case UNPAUSE:
    systime = 0;
    count = 0;
    Gsyncount = 0;
    break;
  default:
    break;
    }
}

void
alphasyn::initParameters()
{
  gmax = 4e-9; // S
  tau = 10e-3; // s
  // esyn = 0; // V excitatory
  esyn = -70e-3; // V inhibitory
  output(0) = 0;
  dt = RT::System::getInstance()->getPeriod() * 1e-9; // s
  systime = 0;
  count = 0;
  Gsyncount = 0;
}

void
alphasyn::initStimulus()
{
  arrGsyn = new double[int(tau * 10 / dt + 1)]; // compute for 10 times tau to get long enough stimulation
  for (int i = 0; i < int(tau * 10 / dt + 1); i++)
    {
      arrGsyn[i] = -1 * gmax * (i * dt) / tau * exp(-(i * dt - tau) / tau);
    }
  nsamples = int(tau * 10 / dt + 1);
  /*  for (int i = 0; i < 5; i++)
   {
   printf("%f \n", arrGsyn[i]*1e9);
   }*/
}
