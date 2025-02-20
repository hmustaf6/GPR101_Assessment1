#include <iostream>

using namespace std;

// Function to calculate additional alloys from surplus minerals
int calculateAlloyProduction(int surplusMinerals) {
    return (surplusMinerals / 50) * 10;
}

int main() {
    // Resource variables
    int mineralProduction, mineralConsumption;
    int energyProduction, energyConsumption;
    int alloyProduction, alloyConsumption;

    // Input from user
    cout << "Enter monthly mineral production: ";
    cin >> mineralProduction;
    cout << "Enter monthly mineral consumption: ";
    cin >> mineralConsumption;
    
    cout << "Enter monthly energy production: ";
    cin >> energyProduction;
    cout << "Enter monthly energy consumption: ";
    cin >> energyConsumption;
    
    cout << "Enter monthly alloy production: ";
    cin >> alloyProduction;
    cout << "Enter monthly alloy consumption: ";
    cin >> alloyConsumption;

    // Net resource calculation
    int netMinerals = mineralProduction - mineralConsumption;
    int netEnergy = energyProduction - energyConsumption;
    int netAlloys = alloyProduction - alloyConsumption;

    // Display net values
    cout << "\nNet Monthly Resource Change:" << endl;
    cout << "Minerals: " << netMinerals << endl;
    cout << "Energy: " << netEnergy << endl;
    cout << "Alloys: " << netAlloys << endl;

    // Resource growth over time
    int totalMinerals6 = netMinerals * 6;
    int totalMinerals12 = netMinerals * 12;
    int totalEnergy6 = netEnergy * 6;
    int totalEnergy12 = netEnergy * 12;
    int totalAlloys6 = netAlloys * 6;
    int totalAlloys12 = netAlloys * 12;

    cout << "\nTotal Resources after 6 months:" << endl;
    cout << "Minerals: " << totalMinerals6 << endl;
    cout << "Energy: " << totalEnergy6 << endl;
    cout << "Alloys: " << totalAlloys6 << endl;
    
    cout << "\nTotal Resources after 12 months:" << endl;
    cout << "Minerals: " << totalMinerals12 << endl;
    cout << "Energy: " << totalEnergy12 << endl;
    cout << "Alloys: " << totalAlloys12 << endl;

    // Alloy conversion from surplus minerals
    int additionalAlloys6 = calculateAlloyProduction(totalMinerals6);
    int additionalAlloys12 = calculateAlloyProduction(totalMinerals12);

    cout << "\nAdditional Alloys producible from surplus minerals:" << endl;
    cout << "After 6 months: " << additionalAlloys6 << " alloys" << endl;
    cout << "After 12 months: " << additionalAlloys12 << " alloys" << endl;

    return 0;
}