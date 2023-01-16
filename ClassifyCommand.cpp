#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand(DefaultIO *dio, Data *data) : Command(dio, data) {
    description = "3. classify data";
}

void ClassifyCommand::execute() {
    if (!data->getTrainIsInit()) {
        dio->write("No train file was uploaded\n");
        return;
    }

    if (!data->getTestIsInit()) {
        dio->write("No test file was uploaded\n");
        return;
    }


    // Classify the data
    multimap<vector<double>, string>::iterator it;
    string classification;
    for (it = data->getUnclisifiedMap.begin(); it != data->getUnclisifiedMap.end(); it++)
    {
        classification= data->getClassifiedData().knnFunc(it->first, data->getDisType(), data->getk());
        data->getUnclisifiedMap.uploadClassification();
    }

    // Inform the user the classification is done
    dio->write("Classifying data complete.\n");
}