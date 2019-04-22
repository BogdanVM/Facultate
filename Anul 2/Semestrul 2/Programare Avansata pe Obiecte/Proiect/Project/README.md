# Proiect PAO

Aplicația realizată ca proiect pentru PAO este un soft pentru administrarea abonamentelor și biletelor de transport în comun ale utilizatorilor.

Clase: 
 - 'interface TransportationMethod' = interfața generală din care vor fi create biletele și abonamentele. Conține 3 getteri pentru proprietățile specifice atât abonamentelor cât și biletelor: valabilitatea în zile, preț, data achiziționării;
 - 'abstract class Ticket implements TransportationMethod' = clasa abstractă Ticket implementează metodele din interfața de mai sus și mai adaugă o proprietate: 'int numberOfRides;'. De aici, vor fi create toate clasele concrete de tip bilet;
 - 'abstract class Subscription implements TransportationMethod' = 
