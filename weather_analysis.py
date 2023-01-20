import requests

weather_types_count = {1: {},  # Двумерный словарь словарей, где каждому месяцу соответствуют типы погод с количеством
                       2: {},
                       3: {},
                       4: {},
                       5: {},
                       6: {},
                       7: {},
                       8: {},
                       9: {},
                       10: {},
                       11: {},
                       12: {}}

weather_frequency = {1: [0, 0, 0],
                     2: [0, 0, 0],
                     3: [0, 0, 0],
                     4: [0, 0, 0],
                     5: [0, 0, 0],
                     6: [0, 0, 0],
                     7: [0, 0, 0],
                     8: [0, 0, 0],
                     9: [0, 0, 0],
                     10: [0, 0, 0],
                     11: [0, 0, 0],
                     12: [0, 0, 0]}

# считвание информации о погоде
for y in range(17, 22):
    # url с персональным api key
    url = "http://api.weatherapi.com/v1/history.json?key=c0b904d57eba4137a66145455222009&q=Moscow&dt=20"
    dash = "-"
    year = str(y)
    for m in range(1, 13): # проход по месяцам
        zero = "0"
        if m//10 != 0:  # если номер месяца больше 10
            month = str(m)
        else:  # если номер месяца меньшее 10, то добавить 0 перед номером
            month = zero + str(m)

        for d in range(1, 29):
            day = str(d)
            full_url = url + year + dash + month + dash + day
            response = requests.get(full_url)
            data = response.json()
            weather_type = data["forecast"]["forecastday"][0]["day"]["condition"]["text"]
            if weather_type in weather_types_count[m]:
                weather_types_count[m][weather_type] += 1
            else:
                weather_types_count[m][weather_type] = 1

# вывод данных о погоде (для отладки)
f1 = open("Moscow_5_years.txt", "w")
for m in weather_types_count:
    print(m)
    month = str(m)
    f1.write(month + ":\n")
    for t in weather_types_count[m]:
        print(t, weather_types_count[m][t])
        f1.write(t + " " + str(weather_types_count[m][t]) + "\n")
    print("\n")
    f1.write("\n")

f1.close()


# анализ погоды

for m in weather_types_count:
    for t in weather_types_count[m]:  # случаи погоды с половинной мощностью
        if t == "Partly cloudy" or t == "Patchy light rain" or \
            t == "Light rain" or t == "Patchy light drizzle" or \
            t == "Light sleet" or t == "Light snow" or t == "Light snow showers" or \
            t == "Light freezing rain" or t == "Light rain shower" or t == "Light drizzle" or \
            t == "Patchy rain possible":
            weather_frequency[m][1] += weather_types_count[m][t]

        elif t == "Sunny":  # солнечная погода - максимальная мощность
            weather_frequency[m][2] += weather_types_count[m][t]
        else:
            weather_frequency[m][0] += weather_types_count[m][t] # плохая погода с коэффициентом 0,2

f2 = open("Moscow_frequency.txt", "w")

# выовд частоты погоды в файл

for m in weather_frequency:
    print(m)
    month = str(m)
    f2.write(month+"\n")
    weather_frequency[m][0] /= 140
    weather_frequency[m][1] /= 140
    weather_frequency[m][2] /= 140
    print(weather_frequency[m][0], weather_frequency[m][1], weather_frequency[m][2], "\n")
    f2.write(str(weather_frequency[m][0]) + " " + str(weather_frequency[m][1]) + " " +\
             str(weather_frequency[m][2])+"\n")

f2.close()
