#include "../../data-structures/src/list.h"
#include "reverseeveryknodes.h"

template <typename T>
Node<T>* ReverseNextKNodes(Node<T>* input, const unsigned int k) {
    Node<T>* temp = input;
    int current_step = (int)k - 1;
    while (current_step > 0 && input != nullptr) {
        temp = input;
        for (int i = 0; i < current_step && temp != nullptr; i++) {
            temp = temp->GetNext();
        }
        if (temp != nullptr) {
            T swap_placeholder = input->GetData();
            input->SetData(temp->GetData());
            temp->SetData(swap_placeholder);
        }
        current_step = current_step - 2;
        input = input->GetNext();
    }
    current_step = (int)(k + 1) / 2;
    while (current_step > 0 && input != nullptr) {
        input = input->GetNext();
        current_step--;
    }
    return input;
}

template <typename T>
List<T> ReverseEveryKNodes(List<T> &input, const unsigned int k) {
    if (input.GetHead() == nullptr) {
        return input;
    }
    Node<T>* temp = ReverseNextKNodes(input.GetHead(), k);
    while (temp != nullptr) {
        temp = ReverseNextKNodes(temp, k);
    }
    return input;
}

template Node<int>* ReverseNextKNodes<int>(Node<int>*, unsigned int); // forward resolution for unit tests
template List<int> ReverseEveryKNodes<int>(List<int>&, unsigned int); // forward resolution for unit tests