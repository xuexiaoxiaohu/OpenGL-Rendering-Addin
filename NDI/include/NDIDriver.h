#ifndef NDIDRIVER_H
#define NDIDRIVER_H

#include <optional>
#include <functional>
#include "ToolData.h"
#include "MarkerData.h"

class NDIDriverImp;

class NDIDriver{

    using errorListener = std::function<void(const std::string&)>;

public:
    /**
     * explicit constructor of NDIDriver
     * @param hostName (required) The measurement device's hostname, IP address, or serial port.
     * @param scuName (optional) A System Control Unit (SCU) hostname, used to connect active tools.
     */
    explicit NDIDriver() = default;
    explicit NDIDriver(const std::string& hostName, const std::string& scuName = "");

    /**
     * destruction
     */
    virtual ~NDIDriver();

    /**
     * callback function for error info
     * @param callback function
     */
    virtual void on_error(const errorListener& callback);

    /**
     * parameter Settings for two versions
     * @param option parameter setting
     */
    virtual void set_option(const std::string& option = "--6d=tools --3d=all --sensor=all --1d=buttons");
    virtual void set_option(uint16_t option = TrackingReplyOption::TransformData | TrackingReplyOption::AllTransforms);

    /**
	 * Sets serial port settings on the device.
	 * @param baudRate Specifies the data transmission rate
	 * @param dataBits Specifies the size of a byte: { 0 = 8 bits, 1 = 7 bits}
	 * @param parity Specifies parity: { 0 = None, 1 = Odd, 2 = Even}
	 * @param stopBits Specifies the number of stop bits: { 0 = 1 bit, 1 = 2 bits}
	 * @param enableHandshake Enables or disables hardware handshaking: { 0 = Off, 1 = On}
	 * @returns Zero for success, or the error code associated with the command.
	 */
    virtual int set_comm_params(CommBaudRateEnum::value baudRate, int dataBits = 0, int parity = 0, int stopBits = 0, int enableHandshake = 1);

    /**
     * Get data from driver
     * @return transform data
     */
    virtual std::optional<std::vector<ToolData>> get_data();

    /**
     * Set the status of tracking
     * @param enable whether to enable the tracking
     * @return is successful
     */
    virtual bool set_tracking_status(bool enable);

    /**
     * Get the time interval of sample
     * @return interval with millisecond
     */
    virtual std::chrono::milliseconds get_sample_interval();

private:
    NDIDriverImp *imp;
};

#endif //NDIDRIVER_H
