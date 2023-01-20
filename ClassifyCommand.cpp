#include "ClassifyCommand.h"

ClassifyCommand::ClassifyCommand(DefaultIO *dio, Data *data) : Command(dio, data) {
    description = "3. classify data";
}

void ClassifyCommand::execute() {
    cout<<"start 3"<<endl;
    if (!data->getTrainIsInit() || !data->getTestIsInit()) {
        cout<<"uploade data"<<endl;
        dio->write("Please upload data\n");
        return;
    }
    //clasify data:
    cout<<"before class"<<endl;
    data->classifyData();
    cout<<"after class"<<endl;
    data->SetIsClassified(true);
    // Inform the user the classification is done
    dio->write("Classifying data complete.\n");
}