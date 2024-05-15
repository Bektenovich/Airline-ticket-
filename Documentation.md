Documentation

Purpose

This program is an Airline Ticket Reservation System implemented in C++. It allows users to add, cancel, and display flight tickets. The system is designed to store ticket information persistently so that it can be accessed across multiple program executions.

Design Decisions

Used a vector to store Ticket objects for easy management and access.
Implemented file I/O to save and load ticket data from a text file for persistence.
Used a simple console-based user interface for interaction.

Algorithms Used

Basic file I/O for reading and writing ticket data to a file.
Linear search algorithm to find and cancel a ticket by ID.

Data Structures Employed

struct Ticket to represent a flight ticket with relevant details.
vector<Ticket> to store multiple ticket objects.

Functions/Modules Created

displayAllTickets(): Displays all the tickets currently stored in the system.
addTicket(): Adds a new ticket to the system.
cancelTicket(): Cancels a ticket based on the user-provided ID.
saveTicketsToFile(): Saves the current list of tickets to a text file.
loadTicketsFromFile(): Loads the list of tickets from a text file into the system.

How to Use the Software

Installation/Setup: No special installation is required. Simply compile the code using a C++ compiler and run the executable.

Using the Program:

Upon running the program, the user is presented with a menu.
The user can choose from the options to display all tickets, add a new ticket, cancel a ticket, or exit the program.
Ticket details are entered by the user when adding a new ticket.
Tickets can be canceled by providing the ID of the ticket to cancel.
All tickets are saved automatically to a file when the program is exited and loaded back when the program is started again.
Screenshots (for demonstration purposes only):
Main Menu:

Adding a Ticket:

Canceling a Ticket:

Displaying All Tickets:
