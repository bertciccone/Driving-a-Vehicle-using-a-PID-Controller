#include "PID.h"

using namespace std;

/*
 * TODO: Complete the PID class.
 */

PID::PID() {
  Kp = 0;
  Ki = 0;
  Kd = 0;
  p_error = 0;
  i_error = 0;
  d_error = 0;
}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  // run Twiddle to initialize coefficients this->Kp, Ki, Kd
}

void PID::UpdateError(double cte) {
  // Update p_error (cte), i_error (cte_int), d_error (cte_diff)
  d_error = cte - p_error; // p_error is previous cte here
  p_error = cte;
  i_error += cte;
}

double PID::TotalError() {
  // Return PID formula for the sum of the component errors
  return Kp * p_error + Ki * i_error + Kd * d_error;
}
