#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Структура для представления билета на рейс
struct Ticket {
    string id;
    string source;
    string destination;
    string date;
    string time;
    int seatsAvailable;
    double price;
};

// Глобальный вектор для хранения билетов
vector<Ticket> tickets;

// Прототипы функций
void displayAllTickets();
void addTicket();
void cancelTicket();
void saveTicketsToFile();
void loadTicketsFromFile();

int main() {
    loadTicketsFromFile(); // Загружаем билеты из файла при запуске

    // Добавляем тестовые данные
    Ticket testTicket1 = {"1", "Bishkek", "London     ", "16/05/2024", "08:00", 10,  500.0};
    tickets.push_back(testTicket1);

    Ticket testTicket2 = {"2", "London", "Paris    ", "17/05/2024", "09:00", 21,  350.0};
    tickets.push_back(testTicket2);

    Ticket testTicket3 = {"3", "Paris", "Bishkek   ", "18/05/2024", "10:00", 7,  400.0};
    tickets.push_back(testTicket3);

    while (true) {
        cout << "\nAirline Ticket Reservation System\n";
        cout << "1. Display all tickets\n";
        cout << "2. Add a new ticket\n";
        cout << "3. Cancel a ticket\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayAllTickets();
                break;
            case 2:
                addTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                saveTicketsToFile();
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}

void displayAllTickets() {
    if (tickets.empty()) {
        cout << "No tickets found. Please add some tickets first.\n";
        return;
    }

    cout << "ID\tSource\tDestination\tDate\t\tTime\tSeats\tPrice\n";
    for (const auto& ticket : tickets) {
        cout << ticket.id << "\t"
             << ticket.source << "\t"
             << ticket.destination << "\t"
             << ticket.date << "\t"
             << ticket.time << "\t"
             << ticket.seatsAvailable << "\t"
             << ticket.price << "\n";
    }
}

void addTicket() {
    Ticket newTicket;
    cout << "Enter ticket details:\n";
    cout << "ID: ";
    cin >> newTicket.id;
    cout << "Source: ";
    cin >> newTicket.source;
    cout << "Destination: ";
    cin >> newTicket.destination;
    cout << "Date: ";
    cin >> newTicket.date;
    cout << "Time: ";
    cin >> newTicket.time;
    cout << "Seats available: ";
    cin >> newTicket.seatsAvailable;
    cout << "Price: ";
    cin >> newTicket.price;

    tickets.push_back(newTicket);
    cout << "Ticket added successfully.\n";
}

void cancelTicket() {
    if (tickets.empty()) {
        cout << "No tickets found to cancel.\n";
        return;
    }

    string ticketId;
    cout << "Enter the ID of the ticket to cancel: ";
    cin >> ticketId;

    bool found = false;
    for (auto it = tickets.begin(); it != tickets.end(); ++it) {
        if (it->id == ticketId) {
            tickets.erase(it);
            found = true;
            cout << "Ticket with ID " << ticketId << " canceled successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "Ticket with ID " << ticketId << " not found.\n";
    }
}

void saveTicketsToFile() {
    ofstream file("tickets.txt");
    if (!file.is_open()) {
        cout << "Failed to open file for writing.\n";
        return;
    }

    for (const auto& ticket : tickets) {
        file << ticket.id << " "
             << ticket.source << " "
             << ticket.destination << " "
             << ticket.date << " "
             << ticket.time << " "
             << ticket.seatsAvailable << " "
             << ticket.price << "\n";
    }

    file.close();
}

void loadTicketsFromFile() {
    ifstream file("tickets.txt");
    if (!file.is_open()) {
        cout << "No saved tickets found.\n";
        return;
    }

    tickets.clear();

    string id, source, destination, date, time;
    int seatsAvailable;
    double price;

    while (file >> id >> source >> destination >> date >> time >> seatsAvailable >> price) {
        Ticket ticket;
        ticket.id = id;
        ticket.source = source;
        ticket.destination = destination;
        ticket.date = date;
        ticket.time = time;
        ticket.seatsAvailable = seatsAvailable;
        ticket.price = price;

        tickets.push_back(ticket);
    }

    file.close();
}
