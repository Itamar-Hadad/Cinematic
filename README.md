# Cinematic: Cinema Management System

Project for the "Object-Oriented Programming Workshop in C++" course. A console-based cinema management system: halls, movies, employees, guests (customers/critics), tickets, and shifts, with an interactive menu-driven `main.cpp`.

## Where this comes from: Part 1 → Part 2 → Part 3

The course project is rolling: each part builds on the previous one.

- **Part 1** (not ours): another team (`DolevTelem_and_EmilGlater_and_OmerAleyRaz`) defined the problem domain and wrote all the original `.h` files, without STL/templates.
- **Part 2**: we picked up that team's Part 1 and implemented all the missing `.cpp` files so the project compiles, links, and runs without bugs. No STL/templates yet, matching the Part 1 constraints. See [`Part2/`](Part2/) below.
- **Part 3**: cross-cutting changes on top of Part 2, templates, `string`/STL migration, and a Singleton manager class. See [`Part3/`](Part3/) below.

This repo holds both snapshots side by side so each part's state stays inspectable on its own, even though the assignment sheet asks for Parts 2 and 3 to be submitted together as one zip.

## Repository layout

```
.
├── Part2/     the project as of the end of Part 2
└── Part3/     the project as of the end of Part 3 (current, most complete state)
```

### `Part2/`

Raw C-style memory management throughout, exactly as Part 1/2 require: `Employee**`/`Guest**`/`Hall**`/`Movie**`/`Shift**` arrays with hand-written `resize*()` helpers inside `Cinema`, `char*` fields on `Person`/`Movie`/`Reviewer`, a plain public `Cinema` constructor (no Singleton yet). Also contains the explanatory PDF for the Part 2 submission (`חלק 2 -קורס תכנות מונחה עצמים C.pdf`), which covers, per the assignment's Part 2 section C: why this specific team's Part 1 was chosen over alternatives, and, for each fix made to the received `.h` files, why the original authors likely wrote it that way and whether the fix was required or recommended.

Build:
```bash
cd Part2
g++ -std=c++17 -Wall -Wextra -o cinema \
    main.cpp Cinema.cpp Movie.cpp Date.cpp Person.cpp \
    Employee.cpp Guest.cpp Customer.cpp Reviewer.cpp \
    Ticket.cpp VIPTicket.cpp \
    Hall.cpp Hall3D.cpp VIPHall.cpp Hall3DVIP.cpp \
    Shift.cpp
./cinema
```

### `Part3/`

The current, most complete state. Part 3 requirements mapped to implementation:

| # | Requirement | Done? | Where |
|---|---|---|---|
| a | Generic linked list using templates (append-only insert, delete, print; no STL types in the implementation) | ✅ | [`Part3/LinkedList.h`](Part3/LinkedList.h): `Node`, `insert`, `remove`, `print`, `getHead`, `getSize`; no STL container is used inside the implementation |
| b | Use the list to replace one of the existing arrays | ✅ | `Cinema` holds `LinkedList<Shift*> shifts` instead of a `Shift**` array (see [`Part3/Cinema.h`](Part3/Cinema.h)) |
| c | Replace all dynamically-allocated `char*` fields with `string` | ✅ | `Person::name`, `Movie::title`, `Reviewer::publicationName`: all `std::string` now |
| d | Replace the remaining arrays with some STL data structure (except the one replaced in b) | ✅ | `Cinema` uses `std::vector<Employee*>`, `vector<Guest*>`, `vector<Hall*>`, `vector<Movie*>`; `Guest` uses `std::vector<Ticket*> tickets` |
| e | Delete the "fives" (copy c'tor, d'tor, assignment operator, and the move pair) that are no longer necessary following the move to string/STL | ✅ mostly | `Movie` (the only type with full value semantics) is now entirely `= default`. No more manual memory management is needed. The identity classes (`Person`, `Guest`, `Customer`, `Reviewer`, `Employee`, `Cinema`, the `Hall` family) still deliberately delete the copy constructor/assignment operator, not because memory management requires it, but as an explicit design decision (identity isn't duplicated). That's a valid decision, not leftover cruft |
| f | Define the manager class as a Singleton | ✅ | [`Part3/Cinema.h`](Part3/Cinema.h): `private` constructor, `static Cinema& getInstance()` (Meyers Singleton) |
| g | Implement at least 2 additional design patterns | Singleton | |

Class structure (brief):
```
Person (abstract: name, id)
├── Employee (birthDate, salary; operator++ = salary raise)
└── Guest (abstract: visitCount, vector<Ticket*> tickets)
    ├── Customer (clubPoints)
    └── Reviewer (publicationName)

Hall (hallNumber, seats[100], const Movie& currentMovie; virtual)
├── Hall3D (virtual public Hall; glassesCount)
├── VIPHall (virtual public Hall; waitersCount)
└── Hall3DVIP : public VIPHall, public Hall3D   ← multiple (diamond) inheritance

Ticket (const Hall& hallRef, seatNumber; virtual calcFinalPrice)
└── VIPTicket (includesMeal)
```

`Cinema` is the managing Singleton: holds all five collections (employees/guests/halls/movies/shifts), owns every object added to it (`operator+=`), and releases them in its destructor.

Objects held by reference (not by copy, as required in Part 1): `Hall` holds `const Movie&`, `Ticket` holds `const Hall&`, `Shift` holds `const Employee&`.

Build:
```bash
cd Part3
g++ -std=c++17 -Wall -Wextra -o cinema \
    main.cpp Cinema.cpp Movie.cpp Date.cpp Person.cpp \
    Employee.cpp Guest.cpp Customer.cpp Reviewer.cpp \
    Ticket.cpp VIPTicket.cpp \
    Hall.cpp Hall3D.cpp VIPHall.cpp Hall3DVIP.cpp \
    Shift.cpp
./cinema
```

Memory leak check:
```bash
valgrind --leak-check=full ./cinema
```

Companion files inside `Part3/`:
- **`CHANGES_LOG.md`** holds the Part 2 change documentation: every change to the original `.h`/`main.cpp` files, why the original authors likely chose what they chose, and whether the change is required or recommended (and why).
- **`IMPLEMENTATION_PLAN.md`** is the original Part 2 work plan (implementing the `.cpp` files on top of the received headers).
- **`IMPLEMENTATION_PLAN_PART3.md`** is the Part 3 work plan (steps a through g in the table above, including suggestions for the additional design patterns in section g).

## Before submitting

Per the assignment sheet: run a `clean` and delete the hidden `vs` folder before zipping the project (the zip file should be only tens of KB, not several MB). Since Part 2 and Part 3 are due together as one zip, zip both `Part2/` and `Part3/`.