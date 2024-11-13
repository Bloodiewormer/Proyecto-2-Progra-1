# Proyecto 2 Escuela 1.2

## Eureka AI School Management System

This project is a Virtual Academy Management System called **Eureka AI School**, developed for the course "Programación I, II ciclo 2024" at the Universidad Nacional de Costa Rica. It provides a comprehensive solution for managing courses, groups, students, professors, and scheduling in a virtual academic environment.

## Table of Contents

- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [File Structure](#file-structure)
- [Contributing](#contributing)
- [License](#license)

## Features

- **Manage Academic Blocks**: Four periods per year (January-March, April-June, July-September, October-December).
- **Courses & Groups Management**: Create courses, open multiple groups per course, and assign schedules.
- **Student Registration**: Enroll new students and manage their information.
- **Professor Management**: Add and manage professors, each responsible for multiple groups.
- **Enrollment & Billing**: Enroll students into groups, generate invoices with applicable discounts.
- **Reports & Searches**: Access information on registered professors, students, and detailed group or period reports.
- **Data Persistence**: Save and load data for courses, blocks, professors, students, and groups via files.

## Requirements

- **Object-Oriented Principles**: The project employs principles such as abstraction, encapsulation, inheritance, and relationships (aggregation, composition, association, dependency).
- **Dynamic Memory Management**: Custom linked-list-based collections without using STL containers.
- **User-Friendly Interface**: Clean, intuitive menu-driven navigation with proper screen clearing.

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/Bloodiewormer/eureka-ai-school-management.git
   ```

2. Open the project in your preferred C++ IDE (e.g., Visual Studio).
3. Build the solution to compile the project.

## Usage

1. Run the `Main.cpp` file to start the application.
2. The system will present a **Main Menu** with the following options:
   - **Administration**: Manage students, professors, blocks, courses, and groups.
   - **Enrollment**: Register or deregister students from groups, with detailed invoice generation.
   - **Reports & Searches**: View information about students, professors, courses, groups, and academic blocks.
   - **Save Data**: Persist data to files to maintain consistency across sessions.
   - **Exit**: Safely close the application.

3. **Submenus**:
   - **Administration Menu**: Add students, professors, academic blocks, courses, create groups, and assign professors.
   - **Enrollment Menu**: Enroll or remove students from groups, ensuring all constraints and rules are followed.
   - **Reports Menu**: Generate reports for professors, students, courses enrolled, and more.

## File Structure

- **Main.cpp**: Entry point of the application.
- **Menu.h / Menu.cpp**: Manages user interface and menu options.
- **Estudiante.h / Estudiante.cpp**: Handles student-related data.
- **Profesor.h / Profesor.cpp**: Manages professor details.
- **Curso.h / Curso.cpp**: Defines course attributes and functionalities.
- **Grupo.h / Grupo.cpp**: Manages groups for courses, linked to schedules.
- **Horario.h / Horario.cpp**: Implements the schedule class.
- **Periodos.h / Periodos.cpp**: Manages academic periods throughout the year.
- **ArchivoManager.h / ArchivoManager.cpp**: Handles file operations for data persistence.
- **Factura.h / Factura.cpp**: Generates detailed invoices, including discounts.

## Contributing

Contributions are welcome! If you'd like to improve the project or fix any issues, please fork the repository and submit a pull request.

## License
This project is licensed under the GNU Affero General Public License v3.0. See the [LICENSE.txt](https://github.com/Bloodiewormer/Proyecto-2-Progra-1/blob/master/LICENSE.txt) file for details.
