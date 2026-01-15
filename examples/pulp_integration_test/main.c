#include <stdio.h>
#include <stdlib.h>

/* Simple controller simulation without complex dependencies like Eigen */

/* Simple PD controller structure */
typedef struct {
    float kp;  /* Proportional gain */
    float kd;  /* Derivative gain */
    float prev_error;
} PDController;

/* Initialize the controller */
void init_controller(PDController *ctrl, float kp, float kd) {
    ctrl->kp = kp;
    ctrl->kd = kd;
    ctrl->prev_error = 0.0f;
}

/* Compute control output */
float compute_control(PDController *ctrl, float setpoint, float current_state) {
    float error = setpoint - current_state;
    float derivative = error - ctrl->prev_error;
    float output = ctrl->kp * error + ctrl->kd * derivative;
    ctrl->prev_error = error;
    return output;
}

/* Simple plant simulation (first-order system) */
float update_plant(float state, float control_input, float dt) {
    /* Simple first-order dynamics: dx/dt = -state + control_input */
    return state + dt * (-state + control_input);
}

int main(void) {
    PDController controller;
    float state = 0.0f;
    float setpoint = 10.0f;
    float dt = 0.1f;
    int num_steps = 20;
    
    /* Initialize controller with some gains */
    init_controller(&controller, 0.5f, 0.1f);
    
    printf("Starting PULP Integration Test - Simple Controller Simulation\n");
    printf("============================================================\n");
    
    /* Run simulation loop */
    for (int step = 0; step < num_steps; step++) {
        /* Compute control output */
        float ctrl_out = compute_control(&controller, setpoint, state);
        
        /* Print in parseable format */
        printf("STEP %d: STATE=%.2f -> CTRL_OUT=%.2f\n", step, state, ctrl_out);
        
        /* Update plant state */
        state = update_plant(state, ctrl_out, dt);
    }
    
    printf("============================================================\n");
    printf("Simulation completed successfully!\n");
    
    return 0;
}
