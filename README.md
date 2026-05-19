<img width="724" height="545" alt="image" src="https://github.com/user-attachments/assets/788083b1-bbf2-413c-8c9f-0a8bcab7f7c2" />
<img width="711" height="453" alt="image" src="https://github.com/user-attachments/assets/e2542ddc-3450-437b-8add-75e9ef12682f" />
<img width="770" height="864" alt="image" src="https://github.com/user-attachments/assets/a5211bf0-13a5-4024-82b8-fe750b917fb9" />



## ABSTRACT 

This work presents the creation of a simulation model for a belt-and-cart system using SolidWorks, Simulink, and MATLAB. The primary goal is to estimate and identify the system's parameters accurately, including mass, damping coefficients (incorporating friction), and belt tension characteristics. The belt-and-cart system is widely utilized in mechanical applications and requires precise modelling to understand its dynamic behaviour. The simulation model is developed by integrating a 3D mechanical design from SolidWorks with Simulink for dynamic analysis. MATLAB is employed for numerical computations and parameter extraction. The damping coefficients account for frictional effects, which are crucial for realistic modelling. The model considers key elements such as the belt's elasticity, cart inertia, and interactions between the belt and pulley system. Parameter estimation is achieved by comparing simulated outputs with experimental data or predefined system behaviours. The proposed approach provides an efficient framework for studying the dynamics of belt-and-cart systems, enabling accurate parameter determination without requiring extensive physical testing. This model serves as a foundation for further studies, including control system design and optimization of similar mechanical systems. 


## INTRODUCTION 

Parameter estimation is a process in which the key parameters of a system are identified by comparing its observed behavior to a mathematical or simulated model. This technique is widely used in engineering and science to fine-tune models for greater accuracy, enabling better predictions and control of system performance. In mechanical systems, parameter estimation helps determine values such as mass, damping coefficients, and stiffness, which are often challenging to measure directly but are critical for understanding system dynamics. Simulink, a MATLAB-based simulation environment, is an essential tool for modelling, simulating, and analysing dynamic systems. It provides a graphical interface for building models using blocks that represent mathematical functions, physical components, and signal processing operations. Simulink is widely used in academia and industry for designing and testing systems ranging from mechanical to electrical and control systems, making it ideal for studying the dynamics of a belt-and-cart system. In this project, we focus on developing a simulation model of a belt-and-cart system using Simulink to estimate its critical parameters. The system consists of a cart driven by a belt-and-pulley mechanism, with dynamics influenced by factors such as mass, belt tension, and damping (including friction). By creating an accurate model and performing parameter estimation, we aim to replicate the system’s behavior and gain deeper insights into its characteristics. This project serves as a hands-on application of parameter estimation techniques and demonstrates the power of Simulink in solving realworld engineering problems. 


## Objective: 

- to develop a simulation model for a belt-and-cart system using Simulink 

- to estimate the system's key parameters accurately. This includes     determining parameters such as cart mass, damping coefficients     (accounting for friction), and belt stiffness, which are essential for     predicting the system's dynamic behavior. The project aims to: 

- Build a comprehensive simulation model in Simulink, integrating the     dynamics of the belt, cart, and pulley system. 

- Utilize parameter estimation techniques to align the simulation results     with experimental or theoretical data, ensuring the model accurately     reflects the real system. 

- Validate the estimated parameters by comparing the simulated outputs     with observed system behavior, demonstrating the reliability of the     simulation. 

- Through this approach, the project highlights the importance of     combining simulation tools like Simulink with parameter estimation     methodologies to analyse, design, and optimize mechatronic     systems effectively 


## Mathematical Model of the System:

1 Electrical equation:

### Ea=(𝑅a+𝐿S)𝐼𝑎(𝑠)+ 𝐾𝑏 ω 

Vin=Ea 2 Mechanical model J𝜔̇ = 𝑇𝑚 −𝑇𝑑𝑎𝑚𝑝𝑖𝑛𝑔 −𝑇𝑠𝑡𝑎𝑡𝑖𝑐 → Neglecting initial condition(static torque) T𝑚 =𝑘𝑡 ×𝐼𝑎(𝑠) 

### T𝑑𝑎𝑚𝑝𝑖𝑛𝑔 = B𝑒𝑞 × ω 

### JeqS ω = 𝑘𝑡× 𝐼𝑎(𝑠)− D𝑒𝑞 × ω 

Deq=Dm+Dmech.sys Jeq=Jm+Jmech.sys Transfer Function:

### ω 

##### 𝑉𝑖𝑛 

##### = 

##### 1 

### R 

##### 𝐾𝑡 

##### (𝑆²𝐽𝑒𝑞 + 𝐷𝑒𝑞𝑆) + 𝑆𝐾𝑏 

 Figure 1 DC Motor Circuit Figure 2 Block Diagram Model Of The System 


## Readings From the System 

A block diagram for Taking Reading from the real system 

- We made a voltage divider circuit to measure the voltage across the     motor through the Arduino Analog pins 

- we divided the voltage across the motor by 3 to be able to measure it     through the Arduino safely As max vin for pins =5 V        _Figure 3 Block Diagram For Motor and Encoder Figure 4 Voltage Divider Circuit_ 


## Parameter Estimation Procedures : 

- We need to make a parameter estimation for R,Kt,Kb,L,D and J 

- the system is 2DOF so we could Estimate 3 Parameter in 1 Experiment So we separate the Parameter estimation to 2 Steps :- 1 - Motor Estimation To estimate R , L , Kb,Kt ,D And J of the Motor Considering the energy conversion     Pm=Tm ω=Pe=e ia→kT ia ω=ke ω ia        kT=ke=k     that’s why we assume that kT=ke=k 

- we take a 4 Readings from our system to estimate the R and K     we solve it and it gives us R and K with an Error 3.64% From Equation Vin = RI+L 𝑑𝑖 𝑑𝑡 +k𝜔 At steady state Vin = RI+k𝜔 

- From this Estimation we take R=4.8 ohm and K=0.5 

K R Vin current N (^) 𝜔 R I +k𝜔 RI+k𝜔-Vin (RI+k𝜔-Vin)² ((RI+k𝜔-Vin)/Vin)x100 0.49 9 4.8 10.3 0.1275 186 19.47787 10.35169 0.051691 0.002672 0.501857 8 0.115 142 14.87021 7.98779 0.01221 0.000149 0.15262 6 0.097 104 10.89085 5.911612 0.08839 0.007812 1.47314 1.5 0.062 24 2.513274 1.554623 0.054623 0.002984 3.64153 Sum 0.013617 _Figure 5 Estimation for R and K_ 


- We build motor Model at figure 16 To estimate L,D,J From the Estimation with 10 iterations and validation we got that Dm= 0.0044 698 N.m/(rad/s) L=4.38 mH Jm=0.0081555 Kg.m 2 _Figure 6 Motor Model Subsystem_ 


Parameter Estimation for motor:Validation _Figure 7 Parameter Estimation Graphs Figure 8 Validation Graphs_ 


2 System Estimation To estimate D and J for the mechanical system We build motor Model at figure(1 7 ) To estimate D and J From the Estimation with 10 iterations and validation we got that D= 0.0044 2798 N.m/(rad/s) J=1.0534× 10 −^5 Kg.m^2 _Figure 9 System Model_ 


Parameter Estimation for System:_Figure 11 Parameter Estimation graphs Figure 10 Validation Graphs_ 


## MATLAB Block Diagram:

1)For Readings:1 Encoder _RPM Filter Figure 12 Encoder Block diagram Figure 13 Filter for Encoder Block diagram_ 


2 Motor Vin:3 Control Direction _Figure 14 Vin Block Diagram Figure 15 Direction Control Circuit_ 


2)For Parameter Estimation : Motor Model:System Model:_Figure 16 Motor Model Figure 17 System Model_ 


## schematic graphical:

 Figure 18 initial schematic Figure 19 initial Cad Design 


## Cad Design:

## Hardware Implementation: 

 Figure 20 CAD Design Figure 21 Hardware Implementation 


## Simscape Multibody 

 Figure 22 Multibody Simscape Simulation Figure 23 Multibody Simscape Blocks 


## Conclusion:

From Parameter estimation Jeq=1.0534× 10 − 5 +0.0081555=8.166034× 10 − 3 Kg.m^2 Deq= 0.0044 2798 +0.0044698 = 8.89778× 10 − 3 N.m/(rad/s) L=4.38 mH R=4.8 ohm K=0.5 So the Transfer Function of the system ω 𝑉𝑖𝑛 

##### = 

 1 R 𝐾𝑡 (𝑆²𝐽𝑒𝑞 + 𝐷𝑒𝑞𝑆) + 𝑆𝐾𝑏 

#### = 

 1 4. 8 0. 5 ( 8. 166034 × 10 −^3 𝑆² + 8. 89778 × 10 −^3 𝑆) + 0. 5 𝑆 Vin N Real System N mathematical System Error% 

10. 7 177 174.5 1.41 8 .85 147 144.2 1.905     7.3 121 119.2 1.653 

4. 458 71.37 72.72 1.9     2 31.3 32.6 4        _Figure 25 parameter Estimation Error_           _Figure 24 mathematical system_ 


## Comment 

- We select the signal pwm volt with 5v(255) because it is more suitable,     stable and lower in error 

- As we take the readings of the volt and rpm from a scope there will be     error in readings 

- As the AVO has an error in current measuring there will be an error 

- Inertia of the motor is high because of the inertia of Gear box 

## Drive Links:

1 Cad simulation https://drive.google.com/file/d/1fQp9lyu9A4hG4bAyTZpTlwYIAIv0jPN/view?usp=sharing 2 Cad Files https://drive.google.com/file/d/1vqIbr92q8fxsMk1YJDZMLcG7s7TOWOm/view?usp=sharing 3 MATLAB Files https://drive.google.com/file/d/1cioaiNM_N_hUcws6125PWbWA_I5uxSz/view?usp=sharing 




https://github.com/user-attachments/assets/3bb75c5b-a4b6-444a-98ba-ffa4dd2a95e5

