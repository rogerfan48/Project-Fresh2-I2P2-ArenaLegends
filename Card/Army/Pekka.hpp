#include "Card/Card.hpp"

#include "Entity/Army/Army.hpp"

class Pekka: public Card {
public:
    Pekka(bool selected, float x, float y);
    Pekka(float x, float y);
    void Draw() const override;
    Army* placeArmy(int instanceID, float xB, float yB) override;
};