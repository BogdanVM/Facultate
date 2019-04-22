# Proiect PAO

Aplicația realizată ca proiect pentru PAO este un soft pentru administrarea abonamentelor și biletelor de transport în comun ale utilizatorilor.

**PACHETUL MODELS**

*Clase abstracte, interfețe și enums:*

 - `interface TransportationMethod` = interfața generală din care vor fi create biletele și abonamentele. Conține 3 getteri pentru proprietățile specifice atât abonamentelor cât și biletelor: valabilitatea în zile, preț, data achiziționării;
 - `abstract class Ticket implements TransportationMethod` = clasa abstractă Ticket implementează metodele din interfața de mai sus și mai adaugă o proprietate: `int numberOfRides;`. De aici, vor fi create toate clasele concrete de tip bilet;
 - `abstract class Subscription implements TransportationMethod` = clasa abstractă Subscription implementează toate metodele din interfață și nu mai adaugă nicio proprietate în plus;
 - `enum TransportationTypes {TICKET, SUBSCRIPTION, ANY}` = această enumerare a fost creată pentru a ușura deosebirea dintre tipurile de TransportationMethods;
 
*Clase concrete:*

 - `class OneRideTicket` / `class TwoRideTicket` / `class TenRideTicket` = clasele concrete derivate din `abstract class Ticket`. În constructor, sunt inițializate valorile pentru proprietățile din `Ticket`;
 - `class OneDaySubscription` / `class OneWeekSubscription` / `class OneMonthSubscription` = clasele concrete derivate din `abstract class Subscription`. La fel ca mai sus, constructorul inițializează proprietățile;

**PACHETUL FACTORIES**

Pentru a instanția clasele din pachetul *models*, am folosit design pattern-ul *abstract factory*. Astfel, în pachetul *factories*, se află toate clasele necesare implementării acestui design pattern.

*Abstract Factory:*
 - `abstract class AbstractTransportationFactory` = clasa abstractă cu o singură metodă abstractă, care va întoarce tipul metodei de transport în funcție de parametrul de tip string;
   - `abstract TransportationMethod getTransportationMethod(String transportationType);`
