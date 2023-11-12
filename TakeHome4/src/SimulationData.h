#ifndef SIMULATION_DATA_H
#define SIMULATION_DATA_H

#include <vector>
#include<iterator>
#include<algorithm>
#include<string>
#include"Observer.h"
#include"Subject.h"

/**
 * @class SimulationData
 * @brief The SimulationData class is a concrete Subject that stores simulation data and notifies its observers when the data changes.
 */
class SimulationData : public Subject
{
public:
    /**
     * @brief Registers an observer to receive notifications when the simulation data changes.
     * @param observer A pointer to the observer to register.
     */
    void registerObserver(Observer* observer) override;

    /**
     * @brief Removes an observer from the list of registered observers.
     * @param observer A pointer to the observer to remove.
     */
    void removeObserver(Observer* observer) override;

    /**
     * @brief Notifies all registered observers that the simulation data has changed.
     */
    void notifyObservers() override;

    /**
     * @brief Sets the message to be stored in the simulation data.
     * @param message The message to set.
     */
    void setMessage(std::string);
private:
    std::vector<Observer*> observers; /**< A vector of pointers to registered observers. */
    std::string message; /**< The message stored in the simulation data. */
};
#endif // !SIMULATION_DATA_H