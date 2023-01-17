#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand(DefaultIO *dio, Data *data) : Command(dio, data) {
    description = "3. classify data";
}

void ClassifyCommand::execute() {
    if (!data->getTrainIsInit() || !data->getTestIsInit()) {
        dio->write("Please upload data\n");
        return;
    }
    //clasify data:
    data->classify();

    // Inform the user the classification is done
    dio->write("Classifying data complete.\n");
}