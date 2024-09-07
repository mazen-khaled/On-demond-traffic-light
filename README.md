# On-Demand Traffic Light System
## Project Overview
This project was developed for Udacity graduation, implementing an on-demand traffic light system that controls the flow of car traffic with pedestrian traffic using MCAL and HAL layers.

<p align="center">
  <img src="https://github.com/user-attachments/assets/16f309d1-70c6-49a9-bf80-4efedf24b3d3" alt="Description">
</p>


## System Design
### MCAL (Microcontroller Abstraction Layer):

- Timer: Used to control the timing and sequencing of the traffic lights.
- GPIO (General Purpose Input/Output): Handles the LED states for traffic lights.
- External Interrupt: Detects the pedestrian button press to switch to pedestrian mode.

### HAL (Hardware Abstraction Layer):
- LED: Represents traffic light indicators (Red, Yellow, Green for cars; Red, Green for pedestrians).
- Button: Pedestrian button to request crossing.

## System Constraints
The system operates in two modes:
1) Normal Mode:
  - Car traffic light operates normally in the sequence of Red → Yellow → Green.
2) Pedestrian Mode (triggered by interrupt):
  - Case 1: If car traffic is Red, pedestrian light turns Green.

    ![Screenshot 2024-09-07 173011](https://github.com/user-attachments/assets/0116ffa7-4ccb-49ce-a76c-2ebc45d4e12e)

  - Case 2: If car traffic is Green, pedestrian light flashes Yellow, then Red for 5 seconds. Afterward, the pedestrian light turns Green, and the car light turns Red for 5 seconds.

    ![Screenshot 2024-09-07 173502](https://github.com/user-attachments/assets/8b6d023d-ff16-4144-a599-ac0794e7352f)

  - Case 3: If car traffic is Yellow, pedestrian light flashes Yellow, then Red for 5 seconds, followed by pedestrian Green and car Red for 5 seconds.

    ![Screenshot 2024-09-07 173212](https://github.com/user-attachments/assets/715dab32-697c-4eed-afd1-589c07768069)

## Flow of the System
### Normal Mode:
- Car traffic light follows a cycle: Red → Yellow → Green, with a 5-second delay between states.
- Timer 0 is used to manage the state transitions using a prescaler of 1024, generating an interrupt every 0.25 seconds, with an initial timer value of 6.
## Pedestrian Mode:
- When the pedestrian button is pressed, an external interrupt is triggered.
- The system enters Pedestrian Mode, and the corresponding logic based on the current car traffic light state is executed through the Interrupt Service Routine (ISR).
