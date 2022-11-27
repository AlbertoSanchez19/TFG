for i = 1:3 
    % Leemos la temperatura del sensor
    temp = readTemperature(mysensehat);
    % Nos la da en Kelvin, por lo que lo pasamos a Celsius.
    temp = temp - 273;
    % Redondeamos para dejar solo un decimal
    temp = round(temp, 1);

    % Hacemos lo mismo para la humedad y presión.
    humidity = readHumidity(mysensehat);
    humidity = round(humidity, 1);

    pressure = readPressure(mysensehat);
    pressure = round(pressure, 1);

    text = ['Temperature: ' num2str(temp) 'C   Humidity: ' num2str(humidity) '   Pressure: ' num2str(pressure)];
    displayMessage(mysensehat, text);

end