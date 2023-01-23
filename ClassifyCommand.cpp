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
    int sizeMap=data->getTrain()->getSizeMap();
    if(data->getK()>sizeMap){
        dio->write("Please make sure k is higher than number vectors in train");
        return;
    }
    data->setResult();
    data->setIsClassified(true);
    // Inform the user the classification is done
    dio->write("Classifying data complete.\n");
}