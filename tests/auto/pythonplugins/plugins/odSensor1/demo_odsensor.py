import random
from odsensor import OdSensor

class EVOPROG_OD_SENSOR(OdSensor):
	
	def __init__(self, params):
		"""constructor"""
		self.i2cAddress = int(params["i2c_address"]);

	def startMeasuring(self, communications, measurementFrequency, wavelength):
		"""must send a command to start reading the optical density sensor, taking samples at "measuremntFrequency" Hz and 
		appliying a ligth of "wavelength" nm.
		
		communication with the machine must be done via communications object.
		ommunications object has the next api:
				*) nbytessend sendString(string) -- send the string to the machine, return the bytes sended;
				*) string receiveString() -- receive and returns a string from the machine (stops when \n is received), can block;
				*) string readUntil(endCharacter) -- returns a string received from the machine, stops when the endCharacter arrives;
				*) void synch() -- synchronize with the machine, not always necesary, only for protocols compatibles;
		"""
		communications.sendString("READ " + str(self.i2cAddress) + " " + str(wavelength));
	
	def getMeasurement(self, communications):
		"""must return a real number with the optical density read by the sensor.
		
		communication with the machine must be done via communications object.
		ommunications object has the next api:
				*) nbytessend sendString(string) -- send the string to the machine, return the bytes sended;
				*) string receiveString() -- receive and returns a string from the machine (stops when \n is received), can block;
				*) string readUntil(endCharacter) -- returns a string received from the machine, stops when the endCharacter arrives;
				*) void synch() -- synchronize with the machine, not always necesary, only for protocols compatibles;
		"""
		return random.sample([0.5,0.6,0.8,0.9,1.2,1.05],1)[0];