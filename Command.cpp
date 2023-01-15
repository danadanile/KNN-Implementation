#include "Command.h"

Command::Command(DefaultIO *my_dio, Data *my_data) : dio(my_dio), data(my_data) {}

string Command::getDescription() const {
    return description;
}

