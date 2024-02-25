#ifndef WORDS_H
#define WORDS_H

static const char *CITIES[] = {
    "paris", "rome", "berlin", "tokyo", "london", "moscow", "cairo", "lima",
    "athens", "seoul", "beijing", "rio", "sydney", "delhi", "dubai", "oslo", "brussels",
    "vienna", "lagos", "mumbai", "lisbon", "prague", "dublin", "bangkok", "riyadh",
    "amman", "kiev", "nairobi", "doha", "brasilia", "ottawa", "tehran", "warsaw",
    "quito", "cusco", "marrakech", "belfast", "hanoi", "copenhagen", "madrid", "riga",
    "tallinn", "stockholm", "manila", "bogota", "montreal", "bucharest", "helsinki", "zurich",
    "budapest", "washington", "athens", "istanbul", "jakarta", "porto", "kolkata",
    "luanda", "beirut", "houston", "lima", "lisbon", "medellin", "casablanca", "osaka"};

static const char *ANIMALS[] = {
    "ant", "baboon", "badger", "bat", "bear", "beaver", "camel", "cat",
    "clam", "cobra", "cougar", "coyote", "crow", "deer", "dog", "donkey",
    "duck", "eagle", "ferret", "fox", "frog", "goat", "goose", "hawk",
    "lion", "lizard", "llama", "mole", "monkey", "moose", "mouse", "mule",
    "newt", "otter", "owl", "panda", "parrot", "pigeon", "python", "rabbit",
    "ram", "rat", "raven", "rhino", "salmon", "seal", "shark", "sheep",
    "skunk", "sloth", "snake", "spider", "stork", "swan", "tiger", "toad",
    "trout", "turkey", "turtle", "weasel", "whale", "wolf", "wombat", "zebra"};

static const char *FOOD[] = {
    "pizza", "pasta", "sushi", "burger", "salad", "sandwich", "steak", "spaghetti",
    "icecream", "chocolate", "pancake", "waffle", "donut", "cupcake", "lasagna", "popcorn",
    "cookie", "taco", "burrito", "noodles", "muffin", "fries", "shrimp", "grapefruit",
    "watermelon", "pineapple", "kiwi", "blueberry", "raspberry", "avocado", "croissant", "baguette",
    "quiche", "cappuccino", "latte", "macaron", "nectarine", "hummus", "falafel",
    "guacamole", "cantaloupe", "cinnamon", "caramel", "fajita", "gazpacho", "gnocchi", "jambalaya",
    "kale", "lentil", "marshmallow", "muesli", "paella", "quinoa", "risotto", "sorbet", "tiramisu",
    "vanilla", "wonton", "zucchini", "biscotti", "cobbler", "dumpling", "eggnog", "frappe"};

static const char *CAR_MANUFACTURERS[] = {
    "toyota", "honda", "ford", "chevrolet", "volkswagen", "nissan", "hyundai", "bmw",
    "mercedes-benz", "audi", "lexus", "kia", "mazda", "subaru", "tesla", "fiat",
    "volvo", "jaguar", "land rover", "porsche", "ferrari", "lamborghini", "maserati", "alfa romeo",
    "jeep", "chrysler", "dodge", "ram", "buick", "cadillac", "gmc", "chevrolet",
    "acura", "infiniti", "lincoln", "mercury", "saturn", "pontiac", "tesla", "hummer",
    "suzuki", "mitsubishi", "isuzu", "koenigsegg", "mclaren", "bugatti", "pagani", "aston martin",
    "lotus", "bentley", "rolls-royce", "maybach", "saab", "smart", "citroen", "peugeot",
    "renault", "fiat", "seat", "skoda", "opel", "vauxhall", "volvo", "geely"};

static const char **CATEGORIES[] = {
    CITIES,
    ANIMALS,
    FOOD,
    CAR_MANUFACTURERS,
};

static const char *CATEGORY_STR[] = {
    "Cities",
    "Animals",
    "Food",
    "Car Manufacturers",
};

#endif