// Part of SAASound copyright 1998-2000 dave hooper <no-brain@mindless.com>
//
// This is the internal implementation (header file) of the SAASound object.
// This is done so that the external interface to the object always stays the same
// (SAASound.h) even though the internal object can change
// .. Meaning future releases don't require relinking everyone elses code against
//    the updated saasound stuff
//
// Version 3.00.0 (23 March 2000)
// (c) 1998-2000 dave @ spc       <no-brain@mindless.com>
//
//////////////////////////////////////////////////////////////////////

#define CLICKCLICKLEVEL 60 /* relative volume of clickclicks ... */
#define CLICKCLICKLEVELTIMES256 15360

class CSAASoundInternal : public CSAASound
{
private:
	int m_nCurrentSaaReg;
	bool m_bOutputEnabled;
	bool m_bSync;
	int m_uParam, m_uParamRate;

	CSAAFreq * Osc[6];
	CSAANoise * Noise[2];
	CSAAAmp * Amp[6];
	CSAAEnv * Env[2];

	// NEW - for emulating bit 4 of OUT 254,xxx
	unsigned int m_bClickClick;
	unsigned int m_bClickClicktimes256;

public:
	CSAASoundInternal();
	~CSAASoundInternal();

	void SetSoundParameters(SAAPARAM uParam);
	void WriteAddress(BYTE nReg);
	void WriteData(BYTE nData);
	void WriteAddressData(BYTE nReg, BYTE nData);
	void Clear(void);
	BYTE ReadAddress(void);

	SAAPARAM GetCurrentSoundParameters(void);
	unsigned long GetCurrentSampleRate(void);
	static unsigned long GetSampleRate(SAAPARAM uParam);
	unsigned short GetCurrentBytesPerSample(void);
	static unsigned short GetBytesPerSample(SAAPARAM uParam);

	void GenerateMany(BYTE * pBuffer, unsigned long nSamples);
	void ClickClick(int bValue);
	// 'Generate' function is obsolete

	int SendCommand(SAACMD nCommandID, long nData);

};