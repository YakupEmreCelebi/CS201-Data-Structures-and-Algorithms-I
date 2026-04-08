// Name: Yakup Emre Çelebi, Section : 2, ID: 22302267, Department: Computer Science

#include "TimeTravelEngine.h"

TimeTravelEngine::TimeTravelEngine()
{

    branches = nullptr;

    numberOfBranches = 0;
}

TimeTravelEngine::~TimeTravelEngine()
{
    if (branches != nullptr)
    {
        for (int i = 0; i < numberOfBranches; i++)
        {
            delete branches[i];
        }

        delete[] branches;
        branches = nullptr;
        numberOfBranches = 0;
    }
}

// TODO
int TimeTravelEngine::findBranchIndex(int branchId) const
{
    for (int i = 0; i < numberOfBranches; i++)
    {
        if (branches[i]->getId() == branchId)
        {
            return i;
        }
    }
    return -1;
}

int TimeTravelEngine::createTimeBranch(const int pastCapacity, const int futureCapacity, const string startLocation, const int branchId)
{
    if (findBranchIndex(branchId) != -1)
    {
        cout << "Cannot create time branch. A branch with ID " << branchId << " already exists." << endl;
        return -1;
    }

    TimeBranch *newBranch = new TimeBranch(branchId, startLocation, pastCapacity, futureCapacity);

    TimeBranch **newArray = new TimeBranch *[numberOfBranches + 1];

    for (int i = 0; i < numberOfBranches; i++)
        newArray[i] = branches[i];

    newArray[numberOfBranches] = newBranch;

    delete[] branches;
    branches = newArray;

    numberOfBranches++;

    cout << "Created time branch with ID " << branchId << "." << endl;
    return branchId;
}

void TimeTravelEngine::deleteTimeBranch(const int branchId)
{

    int idx = findBranchIndex(branchId);
    if (idx == -1)
    {
        cout << "Cannot delete branch. There is no branch with ID " << branchId << "." << endl;
        return;
    }

    delete branches[idx];

    if (numberOfBranches == 1)
    {
        delete[] branches;
        branches = nullptr;
        numberOfBranches = 0;
    }
    else
    {
        TimeBranch **newArray = new TimeBranch *[numberOfBranches - 1];
        int k = 0;
        for (int i = 0; i < numberOfBranches; i++)
        {
            if (i == idx)
            {
                continue;
            }

            newArray[k++] = branches[i];
        }

        delete[] branches;
        branches = newArray;
        numberOfBranches--;
    }

    cout << "Deleted time branch " << branchId << "." << endl;
}

void TimeTravelEngine::printAllBranches() const
{
    if (numberOfBranches == 0)
    {
        cout << "There are no time branches to show." << endl;
        return;
    }

    cout << "Time branches in the system:" << endl;

    TimeBranch **temp = new TimeBranch *[numberOfBranches];
    for (int i = 0; i < numberOfBranches; i++)
    {
        temp[i] = branches[i];
    }

    for (int i = 0; i < numberOfBranches - 1; i++)
    {
        for (int j = 0; j < numberOfBranches - i - 1; j++)
        {
            if (temp[j]->getId() > temp[j + 1]->getId())
            {
                TimeBranch *t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    for (int i = 0; i < numberOfBranches; i++)
    {

        cout << "Branch " << temp[i]->getId() << ":" << endl;
        temp[i]->printBranchState();

        if (i < numberOfBranches - 1)
            cout << endl;
    }

    delete[] temp;
}

void TimeTravelEngine::printTimeBranch(const int branchId) const
{
    int idx = findBranchIndex(branchId);

    if (idx == -1)
        return;

    branches[idx]->printBranchState();
}

void TimeTravelEngine::travelTo(const int branchId, const string newLocation)
{
    int idx = findBranchIndex(branchId);
    if (idx == -1)
    {
        cout << "Cannot travel. There is no branch with ID " << branchId << "." << endl;
        return;
    }
    branches[idx]->travelTo(newLocation);
}

void TimeTravelEngine::fastForward(const int branchId, const int k)
{
    int idx = findBranchIndex(branchId);
    if (idx != -1)
    {
        branches[idx]->fastForward(k);
    }
}

void TimeTravelEngine::rewind(const int branchId, const int k)
{
    int idx = findBranchIndex(branchId);
    if (idx != -1)
    {
        branches[idx]->rewind(k);
    }
}

void TimeTravelEngine::placeTimeStone(const int branchId)
{
    int idx = findBranchIndex(branchId);

    if (idx != -1)
        branches[idx]->placeTimeStone();
}

void TimeTravelEngine::activateTimeStone(const int branchId)
{
    int idx = findBranchIndex(branchId);
    if (idx != -1)
        branches[idx]->activateTimeStone();
}

// TODO
int TimeTravelEngine::mergeBranches(const int branchId1, const int branchId2, const int newBranchId)
{
    int idx1 = findBranchIndex(branchId1);

    int idx2 = findBranchIndex(branchId2);

    if (idx1 == -1 || idx2 == -1)
    {
        cout << "Cannot merge branches. Missing branch IDs." << endl;
        return -1;
    }

    if (findBranchIndex(newBranchId) != -1)
    {
        cout << "Cannot merge branches. A branch with ID " << newBranchId << " already exists." << endl;
        return -1;
    }

    TimeBranch *b1 = branches[idx1];
    TimeBranch *b2 = branches[idx2];

    if (b1->getCurrentLocation() != b2->getCurrentLocation())
    {
        cout << "Cannot merge branches. Current locations do not match." << endl;
        return -1;
    }

    int newPastCap = b1->getPastCapacity() + b2->getPastCapacity();
    int newFutureCap = b1->getFutureCapacity() + b2->getFutureCapacity();
    string startLoc = b1->getCurrentLocation();

    TimeBranch *merged = new TimeBranch(newBranchId, startLoc, newPastCap, newFutureCap);

    StringStack *p1 = b1->getPastStack();
    for (int i = 0; i < p1->size(); i++)
    {
        merged->getPastStack()->push(p1->getElementAt(i));
    }

    StringStack *p2 = b2->getPastStack();
    for (int i = 0; i < p2->size(); i++)
    {
        merged->getPastStack()->push(p2->getElementAt(i));
    }

    StringStack *f1 = b1->getFutureStack();
    for (int i = 0; i < f1->size(); i++)
    {
        merged->getFutureStack()->push(f1->getElementAt(i));
    }

    StringStack *f2 = b2->getFutureStack();
    for (int i = 0; i < f2->size(); i++)
    {
        merged->getFutureStack()->push(f2->getElementAt(i));
    }

    StringStack *s1 = b1->getStoneStack();
    for (int i = 0; i < s1->size(); i++)
    {
        if (merged->getStoneStack()->isFull())
        {
            merged->getStoneStack()->expand();
        }

        merged->getStoneStack()->push(s1->getElementAt(i));
    }

    StringStack *s2 = b2->getStoneStack();
    for (int i = 0; i < s2->size(); i++)
    {
        if (merged->getStoneStack()->isFull())
        {
            merged->getStoneStack()->expand();
        }

        merged->getStoneStack()->push(s2->getElementAt(i));
    }
    TimeBranch **newArr = new TimeBranch *[numberOfBranches - 1];

    int k = 0;

    for (int i = 0; i < numberOfBranches; i++)
    {

        int id = branches[i]->getId();
        if (id == branchId1 || id == branchId2)
        {
            delete branches[i];

            continue;
        }
        newArr[k++] = branches[i];
    }
    newArr[k] = merged;

    delete[] branches;
    branches = newArr;
    numberOfBranches--;

    cout << "Time branches " << branchId1 << " and " << branchId2 << " merged into new branch " << newBranchId << "." << endl;

    return newBranchId;
}
