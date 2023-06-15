#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers (extra points)
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];
   

    Sint16 quad_x[4];
    Sint16 quad_y[4];

    float IKSY_1, IKSY_2, IGREKI_1, IGREKI_2;

    int lenght=100;
    int height=20;

    IKSY_1 = q_x + cos(q_theta) * (lenght / 2);
    IKSY_2 = q_x - cos(q_theta) * (lenght / 2);
    IGREKI_1 = q_y - sin(q_theta) * (lenght / 2);
    IGREKI_2 = q_y + sin(q_theta) * (lenght / 2);
    quad_x[0] = IKSY_1 - sin(q_theta) * (height / 2);
    quad_x[1] = IKSY_1 + sin(q_theta) * (height / 2);
    quad_x[2] = IKSY_2 + sin(q_theta) * (height / 2) ;
    quad_x[3] = IKSY_2 - sin(q_theta) * (height / 2) ;
    quad_y[0] = IGREKI_1 - cos(q_theta) * (height / 2);
    quad_y[1] = IGREKI_1 + cos(q_theta) * (height / 2);
    quad_y[2] = IGREKI_2 + cos(q_theta) * (height / 2) ;
    quad_y[3] = IGREKI_2 - cos(q_theta) * (height / 2) ;
    filledPolygonColor(gRenderer.get(), quad_x, quad_y, 4, 0xff3b3131);
  
}
    
