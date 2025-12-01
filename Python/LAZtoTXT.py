import laspy

# Angi filnavn
input_file = 'C:/Users/edvar/Documents/HINN/Visualisation&Simulation/Datasets/502/data/33-1-497-300-74.laz' # Din LAZ-fil
output_file = 'C:/Users/edvar/Documents/HINN/Visualisation&Simulation/Datasets/502/DatasetV1.txt' # Utdatafil i ASCII-format

# Les LAZ-filen
las = laspy.read(input_file, laz_backend=laspy.LazBackend.Laszip)
# Skriv til ASCII-fil

with open(output_file, 'w') as f:
    #f.write("X Y Z Intensity Classification\n") # Valgfri overskrift
    for x, y, z, in zip(las.x, las.y, las.z):
        f.write(f"({x}, {z}, {y}) ({0}, {1}, {0}) ({0}, {0}) \n")

print(f"LAZ-filen '{input_file}' er eksportert til ASCII-format i filen '{output_file}'.")

