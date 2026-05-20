#include <iostream>
#include <string>

void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail "  << email << std::endl;
}

#include "NotificationsSolution.cpp"



void Notify(const NotifierBase& notifier, const std::string& message) {
    notifier.Notify(message);
}

int main() {
    SmsNotifier sms("+7-495-777-77-77");
    EmailNotifier email("na-derevnyu@dedushke.ru");

    SendSms("+7-495-777-77-77", "Hello! How are you?");
    SendEmail("na-derevnyu@dedushke.ru", "Let's learn C++!");

    Notify(sms, "Hello! How are you?");
    Notify(email, "Let's learn C++!");

    NotifierBase *ptr = new EmailNotifier("+375 28 432 4322");
    ptr->Notify("Hello! How are you?");

    return 0;
}