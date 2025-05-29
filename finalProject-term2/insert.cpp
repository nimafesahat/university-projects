#include <iostream>
#include <fstream>
#include "Location.h"
#include "User.h"
#include "Review.h"
using namespace std;

int main(int argc, const char **argv)
{

    Attraction mashhadAttractions[] = {
        Attraction("Imam Reza Shrine", "Religious", "The largest mosque in the world by area."),
        Attraction("Tomb of Nader Shah", "Historical", "A tomb of the famous Iranian king."),
        Attraction("Kooh Sangi Park", "Nature", "A mountain-side park popular with locals."),
        Attraction("Torghabeh and Shandiz", "Cultural", "Famous villages with traditional food."),
        Attraction("Vakil Abad Park and Zoo", "Family", "A park with zoo, trees, and amusement rides."),
        Attraction("Bazeh Hoor Chahartaq", "Historical", "An ancient Zoroastrian fire temple."),
        Attraction("Mellat Park", "Nature", "A large public park with a lake."),
        Attraction("Gonbad Sabz Garden", "Historical", "A beautiful Persian garden with domes."),
        Attraction("Mahdi Gholi Beyk Historical Bath", "Cultural", "A Safavid-era traditional bathhouse."),
        Attraction("Ferdowsi Tomb in Tus", "Historical", "The resting place of the Persian poet Ferdowsi.")};
    int size = 0;
    ofstream out("attractions.bin", ios::binary | ios::app);
    size = sizeof(mashhadAttractions) / sizeof(mashhadAttractions[0]);
    for (int i = 0; i < size; i++)
    {
        out.write((char *)&mashhadAttractions[i], sizeof(mashhadAttractions[i]));
    }
    out.close();

    Attraction parisAttractions[] = {
        Attraction("Eiffel Tower", "Landmark", "Iconic iron lattice tower and symbol of Paris."),
        Attraction("Louvre Museum", "Museum", "World's largest art museum, home to the Mona Lisa."),
        Attraction("Notre-Dame Cathedral", "Religious", "Famous Gothic cathedral with stained glass windows."),
        Attraction("Champs-Élysées", "Street", "Famous avenue with shops, cafés, and theaters."),
        Attraction("Arc de Triomphe", "Monument", "Triumphal arch honoring those who fought for France."),
        Attraction("Sacré-Cœur Basilica", "Religious", "White basilica offering panoramic city views."),
        Attraction("Palace of Versailles", "Historical", "Lavish royal palace and gardens outside Paris."),
        Attraction("Montmartre", "Cultural", "Artistic neighborhood known for street art and history."),
        Attraction("Sainte-Chapelle", "Religious", "Gothic chapel with magnificent stained glass."),
        Attraction("Luxembourg Gardens", "Nature", "Popular park with statues, fountains, and chairs."),
        Attraction("Musée d'Orsay", "Museum", "Museum housed in a former railway station, focuses on 19th-century art."),
        Attraction("Tuileries Garden", "Nature", "Formal garden between Louvre and Place de la Concorde."),
        Attraction("Place de la Concorde", "Square", "Historic square with Egyptian obelisk."),
        Attraction("Panthéon", "Monument", "Neoclassical mausoleum for notable French citizens."),
        Attraction("Seine River Cruise", "Activity", "Sightseeing boat cruise along the Seine River.")};

    ofstream out1("attractions.bin", ios::binary | ios::app);
    size = sizeof(parisAttractions) / sizeof(parisAttractions[0]);
    for (int i = 0; i < size; i++)
    {
        out1.write((char *)&parisAttractions[i], sizeof(parisAttractions[i]));
    }
    out1.close();

    Attraction isfahanAttractions[] = {
        Attraction("Naqsh-e Jahan Square", "Historical", "UNESCO-listed square with beautiful architecture."),
        Attraction("Shah Mosque", "Religious", "Also known as Imam Mosque, famous for its blue tiles."),
        Attraction("Sheikh Lotfollah Mosque", "Religious", "Unique mosque with no minarets, exquisite dome."),
        Attraction("Ali Qapu Palace", "Historical", "Royal palace overlooking the main square."),
        Attraction("Si-o-se-pol Bridge", "Historical", "Famous bridge with 33 arches over the Zayandeh River."),
        Attraction("Khaju Bridge", "Historical", "Bridge and dam with pavilions and decorated arches."),
        Attraction("Chehel Sotoun Palace", "Historical", "Palace with 40 columns and beautiful gardens."),
        Attraction("Hasht Behesht Palace", "Historical", "Elegant Safavid-era pavilion in a garden."),
        Attraction("Vank Cathedral", "Religious", "Armenian cathedral with Christian and Islamic art."),
        Attraction("Jameh Mosque of Isfahan", "Religious", "One of the oldest mosques in Iran."),
        Attraction("Menar Jonban", "Historical", "Shaking minarets built in the 14th century."),
        Attraction("Atashgah", "Historical", "Ancient Zoroastrian fire temple on a hill."),
        Attraction("Qeysarieh Bazaar", "Market", "Traditional market with handicrafts and carpets."),
        Attraction("Bird Garden", "Nature", "Large aviary with exotic birds."),
        Attraction("Flowers Garden", "Nature", "Botanical garden with themed sections.")};

    ofstream out2("attractions.bin", ios::binary | ios::app);
    size = sizeof(isfahanAttractions) / sizeof(isfahanAttractions[0]);
    for (int i = 0; i < size; i++)
    {
        out2.write((char *)&isfahanAttractions[i], sizeof(isfahanAttractions[i]));
    }
    out2.close();

    Attraction tehranAttractions[] = {
        Attraction("Milad Tower", "Landmark", "One of the tallest towers in the world."),
        Attraction("Azadi Tower", "Landmark", "Iconic symbol of Tehran, built in 1971."),
        Attraction("Golestan Palace", "Historical", "Qajar-era royal complex and UNESCO site."),
        Attraction("National Museum of Iran", "Museum", "Artifacts from prehistoric and Islamic periods."),
        Attraction("Sa'dabad Palace", "Historical", "Former royal complex with multiple museums."),
        Attraction("Niavaran Palace Complex", "Historical", "Palace of the last Shah of Iran."),
        Attraction("Tajrish Bazaar", "Market", "Colorful market in north Tehran."),
        Attraction("Darband", "Nature", "Hiking area with restaurants and beautiful scenery."),
        Attraction("Tehran Grand Bazaar", "Market", "Massive market with traditional goods."),
        Attraction("Nature Bridge (Tabiat)", "Landmark", "Pedestrian bridge with parks and views."),
        Attraction("Iran Mall", "Shopping", "One of the largest malls in the world."),
        Attraction("Museum of Contemporary Art", "Museum", "Home to works by Warhol, Picasso, and others."),
        Attraction("Laleh Park", "Nature", "Popular green space with a great atmosphere."),
        Attraction("Jamshidieh Park", "Nature", "Hilly park at the foot of the Alborz Mountains."),
        Attraction("Mount Tochal", "Nature", "Popular for skiing and hiking near the city.")};

    ofstream out3("attractions.bin", ios::binary | ios::app);
    size = sizeof(tehranAttractions) / sizeof(tehranAttractions[0]);
    for (int i = 0; i < size; i++)
    {
        out3.write((char *)&tehranAttractions[i], sizeof(tehranAttractions[i]));
    }
    out3.close();

    Attraction losAngelesAttractions[] = {
        Attraction("Hollywood Sign", "Landmark", "Famous symbol of the film industry."),
        Attraction("Griffith Observatory", "Science", "Public observatory with great city views."),
        Attraction("Santa Monica Pier", "Recreation", "Iconic pier with an amusement park."),
        Attraction("Venice Beach", "Beach", "Trendy beach with street performers and art."),
        Attraction("The Getty Center", "Museum", "Museum with art, gardens, and architecture."),
        Attraction("Universal Studios Hollywood", "Entertainment", "Theme park and working movie studio."),
        Attraction("Rodeo Drive", "Shopping", "Luxury shopping district in Beverly Hills."),
        Attraction("Hollywood Walk of Fame", "Landmark", "Stars honoring celebrities on the sidewalk."),
        Attraction("Los Angeles County Museum of Art (LACMA)", "Museum", "Largest art museum in the western US."),
        Attraction("Walt Disney Concert Hall", "Culture", "Home of the LA Philharmonic, iconic design."),
        Attraction("Downtown LA", "Urban", "Skyscrapers, museums, and food scenes."),
        Attraction("The Broad", "Museum", "Modern art museum with free admission."),
        Attraction("Runyon Canyon", "Nature", "Popular hiking spot with celebrity sightings."),
        Attraction("La Brea Tar Pits", "Science", "Ice Age fossils preserved in tar."),
        Attraction("Staples Center", "Sports", "Arena hosting NBA games and concerts.")};

    ofstream out4("attractions.bin", ios::binary | ios::app);
    size = sizeof(losAngelesAttractions) / sizeof(losAngelesAttractions[0]);
    for (int i = 0; i < size; i++)
    {
        out4.write((char *)&losAngelesAttractions[i], sizeof(losAngelesAttractions[i]));
    }
    out4.close();

    Location locations[] = {
        Location("Mashhad", "Iran", (sizeof(mashhadAttractions) / sizeof(mashhadAttractions[0])), mashhadAttractions),
        Location("Paris", "France", (sizeof(parisAttractions) / sizeof(parisAttractions[0])), parisAttractions),
        Location("Isfahan", "Iran", (sizeof(isfahanAttractions) / sizeof(isfahanAttractions[0])), isfahanAttractions),
        Location("Tehran", "Iran", (sizeof(tehranAttractions) / sizeof(tehranAttractions[0])), tehranAttractions),
        Location("LosAngeles", "Usa", (sizeof(losAngelesAttractions) / sizeof(losAngelesAttractions[0])), losAngelesAttractions)};

    ofstream out5("locations.bin", ios::binary | ios::app);
    size = sizeof(locations) / sizeof(locations[0]);
    for (int i = 0; i < size; i++)
    {
        out5.write((char *)&locations[i], sizeof(locations[i]));
    }
    out5.close();

    User users[] = {
        User("Alice Johnson", "alice.johnson@example.com"),
        User("Bob Smith", "bob.smith@example.com"),
        User("Carol Lee", "carol.lee@example.com"),
        User("David Kim", "david.kim@example.com"),
        User("Eva Martinez", "eva.martinez@example.com"),
        User("Frank Chen", "frank.chen@example.com"),
        User("Grace Wilson", "grace.wilson@example.com"),
        User("Henry Davis", "henry.davis@example.com"),
        User("Isabel Clark", "isabel.clark@example.com"),
        User("Jack Miller", "jack.miller@example.com")};

    ofstream out6("users.bin", ios::binary | ios::app);
    size = sizeof(users) / sizeof(users[0]);
    for (int i = 0; i < size; i++)
    {
        out6.write((char *)&users[i], sizeof(users[i]));
    }
    out6.close();

    Review reviews[] = {
        // Mashhad Attractions (10)
        Review(5, "Absolutely stunning and peaceful. The Imam Reza Shrine is breathtaking.", mashhadAttractions[0], users[0]),
        Review(4, "Interesting historical site about Nader Shah, but needs better maintenance.", mashhadAttractions[1], users[1]),
        Review(5, "Kooh Sangi offers the best sunset views in Mashhad!", mashhadAttractions[2], users[2]),
        Review(4, "Torghabeh has the most amazing kebabs! Worth the trip.", mashhadAttractions[3], users[3]),
        Review(3, "Vakil Abad Zoo is nice but some enclosures seem small.", mashhadAttractions[4], users[4]),
        Review(5, "Bazeh Hoor is an underrated ancient wonder few tourists see.", mashhadAttractions[5], users[5]),
        Review(4, "Perfect place for family picnics with a beautiful lake.", mashhadAttractions[6], users[6]),
        Review(5, "Gonbad Sabz Garden is a peaceful oasis with stunning architecture.", mashhadAttractions[7], users[7]),
        Review(4, "Fascinating look at traditional Safavid-era bathhouses.", mashhadAttractions[8], users[8]),
        Review(5, "A pilgrimage site for lovers of Persian literature.", mashhadAttractions[9], users[9]),

        // Paris Attractions (15)
        Review(5, "The Eiffel Tower at night is magical beyond words!", parisAttractions[0], users[0]),
        Review(5, "Spent 6 hours here and still didn't see everything!", parisAttractions[1], users[1]),
        Review(4, "Even with reconstruction, the architecture amazes.", parisAttractions[2], users[2]),
        Review(3, "Overrated - just expensive shops and crowded sidewalks.", parisAttractions[3], users[3]),
        Review(5, "Climbing to the top was worth it for the panoramic views.", parisAttractions[4], users[4]),
        Review(5, "The white domes against the Paris skyline are stunning.", parisAttractions[5], users[5]),
        Review(5, "Worth the train ride - the Hall of Mirrors left me speechless.", parisAttractions[6], users[6]),
        Review(4, "Charming artists' quarter but very touristy now.", parisAttractions[7], users[7]),
        Review(5, "The stained glass creates rainbows on the floor - magical!", parisAttractions[8], users[8]),
        Review(4, "My favorite place to read a book and people-watch.", parisAttractions[9], users[9]),
        Review(5, "Impressionist masterpieces in a beautiful setting.", parisAttractions[10], users[0]),
        Review(4, "Perfectly manicured gardens right in the city center.", parisAttractions[11], users[1]),
        Review(3, "Interesting history but mostly just a traffic circle now.", parisAttractions[12], users[2]),
        Review(4, "The Foucault pendulum demonstration is fascinating.", parisAttractions[13], users[3]),
        Review(5, "Romantic way to see Paris's bridges at sunset.", parisAttractions[14], users[4]),

        // Isfahan Attractions (15)
        Review(5, "The most magnificent square I've ever seen!", isfahanAttractions[0], users[5]),
        Review(5, "The tilework changes color with the sunlight - magical.", isfahanAttractions[1], users[6]),
        Review(4, "The acoustics inside the dome are incredible.", isfahanAttractions[2], users[7]),
        Review(4, "Great views of the square from the music room.", isfahanAttractions[3], users[8]),
        Review(5, "Even more beautiful when lit up at night.", isfahanAttractions[4], users[9]),
        Review(5, "Local families gather here in the evenings - wonderful atmosphere.", isfahanAttractions[5], users[0]),
        Review(4, "The frescoes tell amazing historical stories.", isfahanAttractions[6], users[1]),
        Review(3, "Smaller than expected but still beautiful.", isfahanAttractions[7], users[2]),
        Review(5, "Fascinating blend of Armenian and Persian cultures.", isfahanAttractions[8], users[3]),
        Review(4, "You can see architectural evolution across centuries.", isfahanAttractions[9], users[4]),
        Review(3, "The shaking minarets are more impressive in videos.", isfahanAttractions[10], users[5]),
        Review(4, "Great views of Isfahan from this hilltop temple.", isfahanAttractions[11], users[6]),
        Review(5, "Best place to buy authentic Persian handicrafts.", isfahanAttractions[12], users[7]),
        Review(4, "Kids loved seeing all the exotic bird species.", isfahanAttractions[13], users[8]),
        Review(3, "Pretty but smaller than international botanical gardens.", isfahanAttractions[14], users[9]),

        // Tehran Attractions (15)
        Review(4, "The observation deck offers 360° views of Tehran.", tehranAttractions[0], users[0]),
        Review(3, "Iconic but the surrounding traffic ruins the experience.", tehranAttractions[1], users[1]),
        Review(5, "The mirror work in the main hall is breathtaking.", tehranAttractions[2], users[2]),
        Review(4, "Excellent overview of Iran's ancient civilizations.", tehranAttractions[3], users[3]),
        Review(5, "The White Palace gardens are worth the visit alone.", tehranAttractions[4], users[4]),
        Review(4, "Glimpses into the Shah's luxurious lifestyle.", tehranAttractions[5], users[5]),
        Review(5, "The spice section will overwhelm your senses!", tehranAttractions[6], users[6]),
        Review(4, "Great hiking but the tea houses get crowded.", tehranAttractions[7], users[7]),
        Review(5, "You could get lost for days in this massive bazaar.", tehranAttractions[8], users[8]),
        Review(4, "Modern architecture that blends beautifully with nature.", tehranAttractions[9], users[9]),
        Review(3, "Impressive in size but feels like any luxury mall.", tehranAttractions[10], users[0]),
        Review(5, "Surprisingly good collection of Western modern art.", tehranAttractions[11], users[1]),
        Review(4, "Lovely green space in the middle of the city.", tehranAttractions[12], users[2]),
        Review(5, "The waterfall and rock formations are beautiful.", tehranAttractions[13], users[3]),
        Review(4, "The cable car ride offers stunning city views.", tehranAttractions[14], users[4]),

        // Los Angeles Attractions (15)
        Review(3, "Harder to get close to than I expected.", losAngelesAttractions[0], users[5]),
        Review(5, "Best place to see the Hollywood sign AND the city.", losAngelesAttractions[1], users[6]),
        Review(4, "Touristy but the sunset over the Pacific is worth it.", losAngelesAttractions[2], users[7]),
        Review(3, "Interesting people-watching but very crowded.", losAngelesAttractions[3], users[8]),
        Review(5, "The gardens alone are worth the visit.", losAngelesAttractions[4], users[9]),
        Review(5, "Harry Potter world exceeded all expectations!", losAngelesAttractions[5], users[0]),
        Review(2, "Unless you're shopping for luxury cars, skip it.", losAngelesAttractions[6], users[1]),
        Review(3, "More crowded and less glamorous than expected.", losAngelesAttractions[7], users[2]),
        Review(5, "The Urban Light installation is iconic.", losAngelesAttractions[8], users[3]),
        Review(4, "The architecture looks like sailing ships.", losAngelesAttractions[9], users[4]),
        Review(3, "Some interesting spots but overall too spread out.", losAngelesAttractions[10], users[5]),
        Review(4, "Yayoi Kusama's Infinity Rooms are mind-bending.", losAngelesAttractions[11], users[6]),
        Review(4, "Great workout with celebrity spotting potential.", losAngelesAttractions[12], users[7]),
        Review(3, "Interesting but smells strongly of tar.", losAngelesAttractions[13], users[8]),
        Review(4, "Great atmosphere during Lakers games.", losAngelesAttractions[14], users[9])};

    ofstream out7("reviews.bin", ios::binary | ios::app);
    size = sizeof(reviews) / sizeof(reviews[0]);
    for (int i = 0; i < size; i++)
    {
        out7.write((char *)&reviews[i], sizeof(reviews[i]));
    }
    out7.close();
}