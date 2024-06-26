#include "GList.h"

// Specialization of the searchingList method for the user type
template <>

bool GList<user>::searchingList(user* obj) 
{
   Node<user>* temp = root;  // Temporary pointer to traverse the list
    bool check = false;      
    // Check if the list is not empty
    if (temp != NULL) {
        // Traverse the list
        while (temp != NULL) {
            // Check if the current node's data meets the search criteria
            if (obj->getUserName() == temp->_data.getUserName() &&
                obj->getPassword() == temp->_data.getPassword()) {

                check = true;  // Set the flag to true if a match is found

                // Update the input user object with the details from the matching node
                obj->setUserName(temp->_data.getUserName());
                obj->setPassword(temp->_data.getPassword());
                obj->setName(temp->_data.getName());
                obj->setAddress(temp->_data.getAddress());
                obj->setEmail(temp->_data.getEmail());
                obj->setMobile(temp->_data.getMobile());
                obj->setUserID(temp->_data.getUSerID());
            }

            // Move to the next node in the list
            temp = temp->getNext();
        }

        // Return true if the user was found, otherwise return false
        if (check == true) {
            return true;
        }
        else {
           
            return false;
        }
    }

    else {
         // Print a message if the list is empty
         cout << "\nList is Empty!!" << endl;
          return false;
    }
}


