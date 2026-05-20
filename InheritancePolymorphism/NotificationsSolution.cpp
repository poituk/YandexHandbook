#include <string>
#include <iostream>

void SendSms(const std::string& number, const std::string& message) {
    std::cout << "Send '" << message << "' to number " << number << std::endl;
}

void SendEmail(const std::string& email, const std::string& message) {
    std::cout << "Send '" << message << "' to e-mail " << email << std::endl;
}

class NotifierBase
{
private:
    std::string contact;
public:
    NotifierBase(const std::string &contact_) : contact(contact_) {}
    virtual ~NotifierBase() = default;
    virtual void Notify(const std::string &message) const = 0;
    const std::string &getContact() const { return contact; }
};

class SmsNotifier : public NotifierBase
{
public:
    SmsNotifier(const std::string &contact) : NotifierBase(contact) {}
    void Notify(const std::string &message) const override {
        SendSms(getContact(), message);
    }
};

class EmailNotifier : public NotifierBase
{
public:
    EmailNotifier(const std::string &contact) : NotifierBase(contact) {}
    void Notify(const std::string &message) const override {
        SendEmail(getContact(), message);
    }
};