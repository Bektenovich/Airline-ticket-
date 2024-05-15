// Online C++ compiler to run C++ program online
#include <iostream> // библиотека для ввода и вывода
#include <string> // библиотека для работы со строками
#include <vector> // библиотека для работы с векторами

using namespace std; // используем пространство имен std

// Структура для представления билета на рейс
struct Ticket {
    string id; // идентификатор билета
    string source; // пункт отправления
    string destination; // пункт назначения
    string date; // дата
    string time; // время
    int seatsAvailable; // доступные места
    double price; // цена
};

// Глобальный вектор для хранения билетов
vector<Ticket> tickets;

// Прототипы функций
void displayAllTickets(); // функция для отображения всех билетов
void addTicket(); // функция для добавления нового билета
void cancelTicket(); // функция для отмены билета

int main() {
    while (true) {
        cout << "\nAirline Ticket Reservation System\n"; // Выводим заголовок программы
        cout << "1. Display all tickets\n"; // Опция для отображения всех билетов
        cout << "2. Add a new ticket\n"; // Опция для добавления нового билета
        cout << "3. Cancel a ticket\n"; // Опция для отмены билета
        cout << "4. Exit\n"; // Опция для выхода из программы
        cout << "Enter your choice: "; // Ввод выбора пользователя

        int choice; // Переменная для хранения выбора
        cin >> choice; // Считываем выбор пользователя

        switch (choice) {
            case 1:
                displayAllTickets(); // Вызываем функцию отображения всех билетов
                break;
            case 2:
                addTicket(); // Вызываем функцию добавления нового билета
                break;
            case 3:
                cancelTicket(); // Вызываем функцию отмены билета
                break;
            case 4:
                cout << "Exiting program.\n"; // Выводим сообщение о выходе из программы
                return 0; // Возвращаем 0, чтобы завершить программу
            default:
                cout << "Invalid choice. Please try again.\n"; // Выводим сообщение об ошибке при некорректном выборе
        }
    }

    return 0; // Возвращаем 0, чтобы завершить программу
}

// Функция для отображения всех билетов
void displayAllTickets() {
    if (tickets.empty()) { // Проверяем, пуст ли вектор билетов
        cout << "No tickets found. Please add some tickets first.\n"; // Выводим сообщение о том, что билетов нет
        return; // Возвращаемся обратно в главный цикл
    }

    cout << "ID\tSource\tDestination\tDate\t\tTime\tSeats\tPrice\n"; // Выводим заголовок таблицы

    // Перебираем все билеты и выводим их информацию
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

// Функция для добавления нового билета
void addTicket() {
    Ticket newTicket; // Создаем новый объект билета
    cout << "Enter ticket details:\n"; // Выводим приглашение к вводу данных
    cout << "ID: ";
    cin >> newTicket.id; // Считываем идентификатор
    cout << "Source: ";
    cin >> newTicket.source; // Считываем пункт отправления
    cout << "Destination: ";
    cin >> newTicket.destination; // Считываем пункт назначения
    cout << "Date: ";
    cin >> newTicket.date; // Считываем дату
    cout << "Time: ";
    cin >> newTicket.time; // Считываем время
    cout << "Seats available: ";
    cin >> newTicket.seatsAvailable; // Считываем количество доступных мест
    cout << "Price: ";
    cin >> newTicket.price; // Считываем цену

    tickets.push_back(newTicket); // Добавляем новый билет в вектор
    cout << "Ticket added successfully.\n"; // Выводим сообщение об успешном добавлении
}

// Функция для отмены билета
void cancelTicket() {
    if (tickets.empty()) { // Проверяем, пуст ли вектор билетов
        cout << "No tickets found to cancel.\n"; // Выводим сообщение о том, что билетов нет
        return; // Возвращаемся обратно в главный цикл
    }

    string ticketId; // Переменная для хранения идентификатора билета
    cout << "Enter the ID of the ticket to cancel: ";
    cin >> ticketId; // Считываем идентификатор билета, который нужно отменить

    bool found = false; // Флаг для указания на найден ли билет
    for (auto it = tickets.begin(); it != tickets.end(); ++it) { // Перебираем все билеты
        if (it->id == ticketId) { // Если нашли билет с нужным идентификатором
            tickets.erase(it); // Удаляем билет из вектора
            found = true; // Устанавливаем флаг найденного билета
            cout << "Ticket with ID " << ticketId << " canceled successfully.\n"; // Выводим сообщение об успешной отмене
            break; // Выходим из цикла
        }
    }

    if (!found) { // Если билет не был найден
        cout << "Ticket with ID " << ticketId << " not found.\n"; // Выводим сообщение о том, что билет не найден
    }
}
