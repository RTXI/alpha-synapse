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

/*
 * An alpha-type synapse
 */

#include <default_gui_model.h>
#include <math.h>
#include <string>

class alphasyn : public DefaultGUIModel
{

public:

  alphasyn(void);
  virtual
  ~alphasyn(void);

  virtual void
  execute(void);

protected:

  virtual void
  update(DefaultGUIModel::update_flags_t);

private:

  void
  initParameters();
  void
  initStimulus(); // creates template conductance array
  double* arrGsyn; // holds the stimulus conductance values
  int nsamples; // holds the size of arrGsyn
  int Gsyncount; // holds current arrGsyn position

  double Vm;
  double gmax;
  double tau;
  double esyn;
  double dt; // system period
  double Iout;
  double systime;
  long long count;

};
