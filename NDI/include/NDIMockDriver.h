#ifndef NDIMOCKDRIVER_NDIMOCKDRIVER_H
#define NDIMOCKDRIVER_NDIMOCKDRIVER_H

#include "NDIDriver.h"

class NDIMockDriverImp;

class NDIMockDriver : public NDIDriver{
    using errorListener = std::function<void(const std::string&)>;

public:
    /**
     * explicit constructor of NDIDriver
     * @param fileName (required) The measurement device's hostname, IP address, or serial port.
     */
    explicit NDIMockDriver(const std::string& fileName);

    /**
     * destruction
     */
    ~NDIMockDriver() override;

    /**
     * callback function for error info
     * @param callback function
     */
    void on_error(const errorListener& callback) override;

    /**
     * parameter Settings for two versions
     * @param option parameter setting
     */
    void set_option(const std::string& option = "--6d=tools --3d=all --sensor=all --1d=buttons") override;
    void set_option(uint16_t option = TrackingReplyOption::TransformData | TrackingReplyOption::AllTransforms) override;

    /**
	 * Sets serial port settings on the device.
	 * @param baudRate Specifies the data transmission rate
	 * @param dataBits Specifies the size of a byte: { 0 = 8 bits, 1 = 7 bits}
	 * @param parity Specifies parity: { 0 = None, 1 = Odd, 2 = Even}
	 * @param stopBits Specifies the number of stop bits: { 0 = 1 bit, 1 = 2 bits}
	 * @param enableHandshake Enables or disables hardware handshaking: { 0 = Off, 1 = On}
	 * @returns Zero for success, or the error code associated with the command.
	 */
    int set_comm_params(CommBaudRateEnum::value baudRate, int dataBits = 0, int parity = 0, int stopBits = 0, int enableHandshake = 1) override;

    /**
     * Get data from driver
     * @return transform data
     */
    std::optional<std::vector<ToolData>> get_data() override;

    /**
     * Set the status of tracking
     * @param enable whether to enable the tracking
     * @return is successful
     */
    bool set_tracking_status(bool enable) override;

    /**
     * Get the time interval of sample
     * @return interval with millisecond
     */
    std::chrono::milliseconds get_sample_interval() override;

private:
    NDIMockDriverImp *imp;
};

#endif //NDIMOCKDRIVER_NDIMOCKDRIVER_H
