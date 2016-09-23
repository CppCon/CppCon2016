#pragma once

// generated with code_generator/templates2Cpp.plx

// Copyright Crabel Capital Management 2016
// All rights reserved

#include "./mdp3_types.h"

namespace mdp3 {

using Asset = char[6]; ///< Asset
// has semantic type String
using CFICode = char[6];
// has semantic type String
using CHAR = char; ///< char
using Currency = char[3]; ///< Currency
// has semantic type Currency
using InstAttribType = int8_t;
using Int16 = int16_t; ///< int16
using Int32 = int32_t; ///< int32
using Int32NULL = optional<int32_t, 2147483647>;
using Int8 = int8_t; ///< int8
using Int8NULL = optional<int8_t, 127>;
using LocalMktDate = optional<uint16_t, 65535>;
using MDEntryTypeChannelReset = char;
using MDEntryTypeLimits = char;
using MDEntryTypeTrade = char;
using MDEntryTypeVol = char;
using MDFeedType = char[3];
// has semantic type String
using MDUpdateActionNew = int8_t;
using MDUpdateTypeNew = int8_t;
using QuoteReqId = char[23];
// has semantic type String
using SecurityExchange = char[4];
// has semantic type Exchange
using SecurityGroup = char[6];
// has semantic type String
using SecurityIDSource = char;
using SecuritySubType = char[5];
// has semantic type String
using SecurityType = char[6]; ///< SecurityType
// has semantic type String
using Symbol = char[20]; ///< Symbol
// has semantic type String
using Text = char[180]; ///< Text
// has semantic type String
using UnderlyingSymbol = char[20];
// has semantic type String
using UnitOfMeasure = char[30];
// has semantic type String
using UserDefinedInstrument = char;
// has semantic type char
using uInt32 = uint32_t; ///< uInt32
using uInt32NULL = optional<uint32_t, 4294967295>;
using uInt64 = uint64_t; ///< uInt64
using uInt8 = uint8_t; ///< uInt8
using uInt8NULL = optional<uint8_t, 255>;

/// A number representing quantity
/// \note semantic type Qty
struct DecimalQty {
    optional<int32_t, 2147483647> mantissa; ///< mantissa  
    constexpr static int8_t exponent = -4; ///< exponent 
} EXACT_LAYOUT;

/// Decimal
struct FLOAT {
    int64_t mantissa; ///< mantissa
    constexpr static int8_t exponent = -7; ///< exponent 
} EXACT_LAYOUT;

/// Year, Month and Date
/// \note semantic type MonthYear
struct MaturityMonthYear {
    optional<uint16_t, 65535> year; ///< YYYY 
    optional<uint8_t, 255> month; ///< MM 
    optional<uint8_t, 255> day; ///< DD 
    optional<uint8_t, 255> week; ///< WW 
} EXACT_LAYOUT;

/// PRICE
struct PRICE {
    int64_t mantissa; ///< mantissa
    constexpr static int8_t exponent = -7; ///< exponent 
} EXACT_LAYOUT;

/// Price NULL
struct PRICENULL {
    optional<int64_t, 9223372036854775807> mantissa; ///< mantissa 
    constexpr static int8_t exponent = -7; ///< exponent 
} EXACT_LAYOUT;

/// Repeating group dimensions
/// \note semantic type NumInGroup
struct groupSize {
    uint16_t blockLength;
    uint8_t numInGroup;
} EXACT_LAYOUT;

/// 8 Byte aligned repeating group dimensions
/// \note semantic type NumInGroup
/// \note since version 5
struct groupSize8Byte {
    uint16_t blockLength; ///< Length
    char padding[5];
    /// \note offset 7
    uint8_t numInGroup; ///< NumInGroup
} EXACT_LAYOUT;

/// Repeating group dimensions
struct groupSizeEncoding {
    /// \note semantic type Length
    uint16_t blockLength;
    /// \note semantic type NumInGroup
    uint16_t numInGroup;
} EXACT_LAYOUT;

/// Template ID and length of message root
struct messageHeader {
    uint16_t blockLength;
    uint16_t templateId;
    uint16_t schemaId;
    uint16_t version;
} EXACT_LAYOUT;

enum class AggressorSide: uint8_t {
    NoAggressor = 0, ///< No Aggressor
    Buy = 1, ///< Buy
    Sell = 2, ///< Sell
    null_value = 255
};

enum class EventType: uint8_t {
    Activation = 5, ///< Activation
    LastEligibleTradeDate = 7, ///< Last Eligible Trade Date
};

enum class HaltReason: uint8_t {
    GroupSchedule = 0, ///< Group Schedule
    SurveillanceIntervention = 1, ///< Surveillance Intervention 
    MarketEvent = 2, ///< Market Event 
    InstrumentActivation = 3, ///< Instrument Activation
    InstrumentExpiration = 4, ///< Instrument Expiration
    Unknown = 5, ///< Unknown
    RecoveryInProcess = 6, ///< Recovery In Process
};

enum class LegSide: uint8_t {
    BuySide = 1, ///< Buy Side
    SellSide = 2, ///< Sell Side
};

enum class MDEntryType: char {
    Bid = '0', ///< Bid
    Offer = '1', ///< Offer
    Trade = '2', ///< Trade
    OpenPrice = '4', ///< Open Price
    SettlementPrice = '6', ///< Settlement Price
    TradingSessionHighPrice = '7', ///< Trading Session High Price
    TradingSessionLowPrice = '8', ///< Trading Session Low Price
    ClearedVolume = 'B', ///< Cleared Volume
    OpenInterest = 'C', ///< Open Interest
    ImpliedBid = 'E', ///< Implied Bid
    ImpliedOffer = 'F', ///< Implied Offer
    BookReset = 'J', ///< Book Reset
    SessionHighBid = 'N', ///< Session High Bid
    SessionLowOffer = 'O', ///< Session Low Offer
    FixingPrice = 'W', ///< Fixing Price
    ElectronicVolume = 'e', ///< Electronic Volume
    ThresholdLimitsandPriceBandVariation = 'g', ///< Threshold Limits and Price Band Variation
};

enum class MDEntryTypeBook: char {
    Bid = '0', ///< Bid
    Offer = '1', ///< Offer
    ImpliedBid = 'E', ///< Implied Bid
    ImpliedOffer = 'F', ///< Implied Offer
    BookReset = 'J', ///< Book Reset
};

enum class MDEntryTypeDailyStatistics: char {
    SettlementPrice = '6', ///< Settlement Price
    ClearedVolume = 'B', ///< Cleared Volume
    OpenInterest = 'C', ///< Open Interest
    FixingPrice = 'W', ///< Fixing Price
};

enum class MDEntryTypeStatistics: char {
    OpenPrice = '4', ///< Open Price
    HighTrade = '7', ///< High Trade
    LowTrade = '8', ///< Low Trade
    HighestBid = 'N', ///< Highest Bid
    LowestOffer = 'O', ///< Lowest Offer
};

enum class MDUpdateAction: uint8_t {
    New = 0, ///< New
    Change = 1, ///< Change
    Delete = 2, ///< Delete
    DeleteThru = 3, ///< Delete Thru
    DeleteFrom = 4, ///< Delete From
    Overlay = 5, ///< Overlay
};

enum class OpenCloseSettlFlag: uint8_t {
    DailyOpenPrice = 0, ///< Daily Open Price
    IndicativeOpeningPrice = 5, ///< Indicative Opening Price
    null_value = 255
};

enum class PutOrCall: uint8_t {
    Put = 0, ///< Put Option
    Call = 1, ///< Call Option
};

enum class SecurityTradingEvent: uint8_t {
    NoEvent = 0, ///< No Event
    NoCancel = 1, ///< No Cancel
    ResetStatistics = 4, ///< Reset Statistics
    ImpliedMatchingON = 5, ///< Implied Matching ON
    ImpliedMatchingOFF = 6, ///< Implied Matching OFF
};

enum class SecurityTradingStatus: uint8_t {
    TradingHalt = 2, ///< Trading Halt
    Close = 4, ///< Close
    NewPriceIndication = 15, ///< New Price Indication
    ReadyToTrade = 17, ///< Ready To Trade
    NotAvailableForTrading = 18, ///< Not Available For Trading
    UnknownorInvalid = 20, ///< Unknown or Invalid
    PreOpen = 21, ///< Pre Open
    PreCross = 24, ///< Pre Cross
    Cross = 25, ///< Cross
    PostClose = 26, ///< Post Close
    NoChange = 103, ///< No Change
    null_value = 255
};

enum class SecurityUpdateAction: char {
    Add = 'A', ///< Add
    Delete = 'D', ///< Delete
    Modify = 'M', ///< Modify
};

union InstAttribValue {
    enum class flags: uInt32 {
        ElectronicMatchEligible = 1 << 0,
        OrderCrossEligible = 1 << 1,
        BlockTradeEligible = 1 << 2,
        EFPEligible = 1 << 3,
        EBFEligible = 1 << 4,
        EFSEligible = 1 << 5,
        EFREligible = 1 << 6,
        OTCEligible = 1 << 7,
        iLinkIndicativeMassQuotingEligible = 1 << 8,
        NegativeStrikeEligible = 1 << 9,
        NegativePriceOutrightEligible = 1 << 10,
        IsFractional = 1 << 11,
        VolatilityQuotedOption = 1 << 12,
        RFQCrossEligible = 1 << 13,
        ZeroPriceOutrightEligible = 1 << 14,
        DecayingProductEligibility = 1 << 15,
        VariableProductEligibility = 1 << 16,
        DailyProductEligibility = 1 << 17,
        GTOrdersEligibility = 1 << 18,
        ImpliedMatchingEligibility = 1 << 19
    };
    uInt32 code;
    struct {
        bool ElectronicMatchEligible:1;
        bool OrderCrossEligible:1;
        bool BlockTradeEligible:1;
        bool EFPEligible:1;
        bool EBFEligible:1;
        bool EFSEligible:1;
        bool EFREligible:1;
        bool OTCEligible:1;
        bool iLinkIndicativeMassQuotingEligible:1;
        bool NegativeStrikeEligible:1;
        bool NegativePriceOutrightEligible:1;
        bool IsFractional:1;
        bool VolatilityQuotedOption:1;
        bool RFQCrossEligible:1;
        bool ZeroPriceOutrightEligible:1;
        bool DecayingProductEligibility:1;
        bool VariableProductEligibility:1;
        bool DailyProductEligibility:1;
        bool GTOrdersEligibility:1;
        bool ImpliedMatchingEligibility:1;
    } EXACT_LAYOUT;
} EXACT_LAYOUT;

union MatchEventIndicator {
    enum class flags: uInt8 {
        LastTradeMsg = 1 << 0,
        LastVolumeMsg = 1 << 1,
        LastQuoteMsg = 1 << 2,
        LastStatsMsg = 1 << 3,
        LastImpliedMsg = 1 << 4,
        RecoveryMsg = 1 << 5,
        Reserved = 1 << 6,
        EndOfEvent = 1 << 7
    };
    uInt8 code;
    struct {
        bool LastTradeMsg:1;
        bool LastVolumeMsg:1;
        bool LastQuoteMsg:1;
        bool LastStatsMsg:1;
        bool LastImpliedMsg:1;
        bool RecoveryMsg:1;
        bool Reserved:1;
        bool EndOfEvent:1;
    } EXACT_LAYOUT;
} EXACT_LAYOUT;

union SettlPriceType {
    enum class flags: uInt8 {
        Final = 1 << 0,
        Actual = 1 << 1,
        Rounded = 1 << 2,
        Intraday = 1 << 3,
        ReservedBits = 1 << 4,
        NullValue = 1 << 7
    };
    uInt8 code;
    struct {
        bool Final:1;
        bool Actual:1;
        bool Rounded:1;
        bool Intraday:1;
        bool ReservedBits:1;
    unsigned padding: 2;
        bool NullValue:1;
    } EXACT_LAYOUT;
} EXACT_LAYOUT;

// Message ChannelReset
template<> struct group_element_t<4, 0> {
    using dimension = groupSize;
    constexpr static MDUpdateTypeNew _MDUpdateAction = 0;
    constexpr static MDEntryTypeChannelReset _MDEntryType = 'J';
    Int16 _ApplID; ///< Indicates the channel ID as defined in the XML configuration file 0
} EXACT_LAYOUT;
using MDEntries_m4 = group_element_t<4, 0>;
template<> struct message_t<4> {
    uInt64 _TransactTime; ///< Start of event processing time in number of nanoseconds since Unix epoch 0
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 8
} EXACT_LAYOUT;
using ChannelReset = message_t<4>;

// Message AdminHeartbeat
template<> struct message_t<12> {
} EXACT_LAYOUT;
using AdminHeartbeat = message_t<12>;

// Message AdminLogin
template<> struct message_t<15> {
    Int8 _HeartBtInt; ///< Heartbeat interval (seconds) 0
} EXACT_LAYOUT;
using AdminLogin = message_t<15>;

// Message AdminLogout
template<> struct message_t<16> {
    Text _Text; ///< Free format text string. May include logout confirmation or reason for logout 0
} EXACT_LAYOUT;
using AdminLogout = message_t<16>;

// Message MDInstrumentDefinitionFuture
template<> struct group_element_t<27, 0> {
    using dimension = groupSize;
    EventType _EventType; ///< Code to represent the type of event 0
    uInt64 _EventTime; ///< Date and Time of instument Activation or Expiration event sent as number of nanoseconds since Unix epoch 1
} EXACT_LAYOUT;
using Events_m27 = group_element_t<27, 0>;
template<> struct group_element_t<27, 1> {
    using dimension = groupSize;
    MDFeedType _MDFeedType; ///< Describes a class of service for a given data feed. GBX- Real Book, GBI-Implied Book 0
    Int8 _MarketDepth; ///< Book depth 3
} EXACT_LAYOUT;
using MDFeedTypes_m27 = group_element_t<27, 1>;
template<> struct group_element_t<27, 2> {
    using dimension = groupSize;
    constexpr static InstAttribType _InstAttribType = 24;
    InstAttribValue _InstAttribValue; ///< Bitmap field of 32 Boolean type instrument eligibility flags 0
} EXACT_LAYOUT;
using InstAttrib_m27 = group_element_t<27, 2>;
template<> struct group_element_t<27, 3> {
    using dimension = groupSize;
    Int8 _LotType; ///< This tag is required to interpret the value in tag 1231-MinLotSize 0
    DecimalQty _MinLotSize; ///< Minimum quantity accepted for order entry. If tag 1093-LotType=4, this value is the minimum quantity for order entry expressed in the applicable units, specified in tag 996-UnitOfMeasure, e.g. megawatts 1
} EXACT_LAYOUT;
using LotTypeRules_m27 = group_element_t<27, 3>;
template<> struct message_t<27> {
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 0
    uInt32NULL _TotNumReports; ///< Total number of instruments in the Replay loop. Used on Replay Feed only  1
    SecurityUpdateAction _SecurityUpdateAction; ///< Last Security update action on Incremental feed, 'D' or 'M' is used when a mid-week deletion or modification (i.e. extension) occurs 5
    uInt64 _LastUpdateTime; ///< Timestamp of when the instrument was last added, modified or deleted 6
    SecurityTradingStatus _MDSecurityTradingStatus; ///< Identifies the current state of the instrument. In Security Definition message this tag is available in the Instrument Replay feed only  14
    Int16 _ApplID; ///< The channel ID as defined in the XML Configuration file 15
    uInt8 _MarketSegmentID; ///< Identifies the market segment, populated for all CME Globex instruments 17
    uInt8 _UnderlyingProduct; ///< Product complex 18
    SecurityExchange _SecurityExchange; ///< Exchange used to identify a security 19
    SecurityGroup _SecurityGroup; ///< Security Group Code. 23
    Asset _Asset; ///< The underlying asset code also known as Product Code 29
    Symbol _Symbol; ///< Instrument Name or Symbol  35
    Int32 _SecurityID; ///< Unique instrument ID 55
    constexpr static SecurityIDSource _SecurityIDSource = '8';
    SecurityType _SecurityType; ///< Security Type 59
    CFICode _CFICode; ///< ISO standard instrument categorization code 65
    MaturityMonthYear _MaturityMonthYear; ///< This field provides the actual calendar date for contract maturity 71
    Currency _Currency; ///< Identifies currency used for price 76
    Currency _SettlCurrency; ///< Identifies currency used for settlement, if different from trading currency 79
    CHAR _MatchAlgorithm; ///< Matching algorithm  82
    uInt32 _MinTradeVol; ///< The minimum trading volume for a security 83
    uInt32 _MaxTradeVol; ///< The maximum trading volume for a security 87
    PRICE _MinPriceIncrement; ///< Minimum constant tick for the instrument, sent only if instrument is non-VTT (Variable Tick table) eligible 91
    FLOAT _DisplayFactor; ///< Contains the multiplier to convert the CME Globex display price to the conventional price 99
    uInt8NULL _MainFraction; ///< Price Denominator of Main Fraction 107
    uInt8NULL _SubFraction; ///< Price Denominator of Sub Fraction 108
    uInt8NULL _PriceDisplayFormat; ///< Number of decimals in fractional display price 109
    UnitOfMeasure _UnitOfMeasure; ///< Unit of measure for the products' original contract size. This will be populated for all products listed on CME Globex 110
    PRICENULL _UnitOfMeasureQty; ///< This field contains the contract size for each instrument. Used in combination with tag 996-UnitofMeasure 140
    PRICENULL _TradingReferencePrice; ///< Reference price for prelisted instruments or the last calculated Settlement whether it be Theoretical, Preliminary or a Final Settle of the session. 148
    SettlPriceType _SettlPriceType; ///< Bitmap field of eight Boolean type indicators representing settlement price type 156
    Int32NULL _OpenInterestQty; ///< The total open interest for the market at the close of the prior trading session. 157
    Int32NULL _ClearedVolume; ///< The total cleared volume of instrument traded during the prior trading session. 161
    PRICENULL _HighLimitPrice; ///< Allowable high limit price for the trading day 165
    PRICENULL _LowLimitPrice; ///< Allowable low limit price for the trading day 173
    PRICENULL _MaxPriceVariation; ///< Differential value for price banding. 181
    Int32NULL _DecayQuantity; ///< Indicates the quantity that a contract will decay daily by once the decay start date is reached 189
    LocalMktDate _DecayStartDate; ///< Indicates the date at which a decaying contract will begin to decay 193
    Int32NULL _OriginalContractSize; ///< Fixed contract value assigned to each product 195
    Int32NULL _ContractMultiplier; ///< Number of deliverable units per instrument, e.g., peak days in maturity month or number of calendar days in maturity month 199
    Int8NULL _ContractMultiplierUnit; ///< Indicates the type of multiplier being applied to the product. Optionally used in combination with tag 231-ContractMultiplier 203
    Int8NULL _FlowScheduleType; ///< The schedule according to which the electricity is delivered in a physical contract, or priced in a financial contract. Specifies whether the contract is defined according to the Easter Peak, Eastern Off-Peak, Western Peak or Western Off-Peak. 204
    PRICENULL _MinPriceIncrementAmount; ///< Monetary value equivalent to the minimum price fluctuation 205
    UserDefinedInstrument _UserDefinedInstrument; ///< User-defined instruments flag 213
    LocalMktDate _TradingReferenceDate; ///< Indicates session date corresponding to the settlement price in tag 1150-TradingReferencePrice 214
} EXACT_LAYOUT;
using MDInstrumentDefinitionFuture = message_t<27>;

// Message MDInstrumentDefinitionSpread
template<> struct group_element_t<29, 0> {
    using dimension = groupSize;
    EventType _EventType; ///< Code to represent the type of event 0
    uInt64 _EventTime; ///< Date and time of instument Activation or Expiration event sent as number of nanoseconds since Unix epoch 1
} EXACT_LAYOUT;
using Events_m29 = group_element_t<29, 0>;
template<> struct group_element_t<29, 1> {
    using dimension = groupSize;
    MDFeedType _MDFeedType; ///< Describes a class of service for a given data feed. GBX- Real Book, GBI-Implied Book 0
    Int8 _MarketDepth; ///< Identifies the depth of book 3
} EXACT_LAYOUT;
using MDFeedTypes_m29 = group_element_t<29, 1>;
template<> struct group_element_t<29, 2> {
    using dimension = groupSize;
    constexpr static InstAttribType _InstAttribType = 24;
    InstAttribValue _InstAttribValue; ///< Bitmap field of 32 Boolean type Instrument eligibility flags 0
} EXACT_LAYOUT;
using InstAttrib_m29 = group_element_t<29, 2>;
template<> struct group_element_t<29, 3> {
    using dimension = groupSize;
    Int8 _LotType; ///< This tag is required to interpret the value in tag 1231-MinLotSize 0
    DecimalQty _MinLotSize; ///< Minimum quantity accepted for order entry. If tag 1093-LotType=4, this value is the minimum quantity for order entry expressed in the applicable units, specified in tag 996-UnitOfMeasure, e.g. megawatts 1
} EXACT_LAYOUT;
using LotTypeRules_m29 = group_element_t<29, 3>;
template<> struct group_element_t<29, 4> {
    using dimension = groupSize;
    Int32 _LegSecurityID; ///< Leg Security ID 0
    constexpr static SecurityIDSource _LegSecurityIDSource = '8';
    LegSide _LegSide; ///< Leg side 4
    Int8 _LegRatioQty; ///< Leg ratio of quantity for this individual leg relative to the entire multi-leg instrument 5
    PRICENULL _LegPrice; ///< Price for the future leg of a UDS Covered instrument  6
    DecimalQty _LegOptionDelta; ///< Delta used to calculate the quantity of futures used to cover the option or option strategy 14
} EXACT_LAYOUT;
using Legs_m29 = group_element_t<29, 4>;
template<> struct message_t<29> {
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 0
    uInt32NULL _TotNumReports; ///< Total number of instruments in the Replay loop. Used on Replay Feed only 1
    SecurityUpdateAction _SecurityUpdateAction; ///< Last Security update action on Incremental feed, 'D' or 'M' is used when a mid-week deletion or modification (i.e. extension) occurs 5
    uInt64 _LastUpdateTime; ///< Timestamp of when the instrument was last added, modified or deleted 6
    SecurityTradingStatus _MDSecurityTradingStatus; ///< Identifies the current state of the instrument. The data is available in the Instrument Replay feed only 14
    Int16 _ApplID; ///< The channel ID as defined in the XML Configuration file 15
    uInt8 _MarketSegmentID; ///< Identifies the market segment, populated for all CME Globex instruments 17
    uInt8NULL _UnderlyingProduct; ///< Product complex 18
    SecurityExchange _SecurityExchange; ///< Exchange used to identify a security 19
    SecurityGroup _SecurityGroup; ///< Security Group Code 23
    Asset _Asset; ///< The underlying asset code also known as Product Code 29
    Symbol _Symbol; ///< Instrument Name or Symbol. Previously used as  Group Code  35
    Int32 _SecurityID; ///< Unique instrument ID 55
    constexpr static SecurityIDSource _SecurityIDSource = '8';
    SecurityType _SecurityType; ///< Security Type 59
    CFICode _CFICode; ///< ISO standard instrument categorization code 65
    MaturityMonthYear _MaturityMonthYear; ///< This field provides the actual calendar date for contract maturity 71
    Currency _Currency; ///< Identifies currency used for price 76
    SecuritySubType _SecuritySubType; ///< Strategy type 79
    UserDefinedInstrument _UserDefinedInstrument; ///< User-defined instruments flag 84
    CHAR _MatchAlgorithm; ///< Matching algorithm 85
    uInt32 _MinTradeVol; ///< The minimum trading volume for a security 86
    uInt32 _MaxTradeVol; ///< The maximum trading volume for a security 90
    PRICE _MinPriceIncrement; ///< Minimum constant tick for the instrument, sent only if instrument is non-VTT (Variable Tick table) eligible 94
    FLOAT _DisplayFactor; ///< Contains the multiplier to convert the CME Globex display price to the conventional price 102
    uInt8NULL _PriceDisplayFormat; ///< Number of decimals in fractional display price 110
    PRICENULL _PriceRatio; ///< Used for price calculation in spread and leg pricing 111
    Int8NULL _TickRule; ///< Tick Rule  119
    UnitOfMeasure _UnitOfMeasure; ///< Unit of measure for the products' original contract size 120
    PRICENULL _TradingReferencePrice; ///< Reference price - the most recently available Settlement whether it be Theoretical, Preliminary or a Final Settle of the session 150
    SettlPriceType _SettlPriceType; ///< Bitmap field of eight Boolean type indicators representing settlement price type 158
    Int32NULL _OpenInterestQty; ///< The total open interest for the market at the close of the prior trading session 159
    Int32NULL _ClearedVolume; ///< The total cleared volume of instrument traded during the prior trading session 163
    PRICENULL _HighLimitPrice; ///< Allowable high limit price for the trading day 167
    PRICENULL _LowLimitPrice; ///< Allowable low limit price for the trading day 175
    PRICENULL _MaxPriceVariation; ///< Differential value for price banding 183
    uInt8NULL _MainFraction; ///< Price Denominator of Main Fraction 191
    uInt8NULL _SubFraction; ///< Price Denominator of Sub Fraction 192
    LocalMktDate _TradingReferenceDate; ///< Indicates session date corresponding to the settlement price in tag 1150-TradingReferencePrice 193
} EXACT_LAYOUT;
using MDInstrumentDefinitionSpread = message_t<29>;

// Message SecurityStatus
template<> struct message_t<30> {
    uInt64 _TransactTime; ///< Start of event processing time in number of nanoseconds since Unix epoch. 0
    SecurityGroup _SecurityGroup; ///< Security Group 8
    Asset _Asset; ///< Product Code within Security Group specified 14
    Int32NULL _SecurityID; ///< If this tag is present, 35=f message is sent for the instrument 20
    LocalMktDate _TradeDate; ///< Trade Session Date 24
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 26
    SecurityTradingStatus _SecurityTradingStatus; ///< Identifies the trading status applicable to the instrument or Security Group 27
    HaltReason _HaltReason; ///< Identifies the reason for the status change 28
    SecurityTradingEvent _SecurityTradingEvent; ///< Identifies an additional event or a rule related to the status 29
} EXACT_LAYOUT;
using SecurityStatus = message_t<30>;

// Message MDIncrementalRefreshBook
template<> struct group_element_t<32, 0> {
    using dimension = groupSize;
    PRICENULL _MDEntryPx; ///< Market Data entry price 0
    Int32NULL _MDEntrySize; ///< Market Data entry size 8
    Int32 _SecurityID; ///< Security ID 12
    uInt32 _RptSeq; ///< Market Data entry sequence number per instrument update 16
    Int32NULL _NumberOfOrders; ///< In Book entry - aggregate number of orders at given price level 20
    uInt8 _MDPriceLevel; ///< Aggregate book level 24
    MDUpdateAction _MDUpdateAction; ///<  Market Data update action 25
    MDEntryTypeBook _MDEntryType; ///< Market Data entry type 26
    char padding[5];
} EXACT_LAYOUT;
using MDEntries_m32 = group_element_t<32, 0>;
template<> struct message_t<32> {
    uInt64 _TransactTime; ///< Start of event processing time in number of nanoseconds since Unix epoch 0
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 8
    char padding[2];
} EXACT_LAYOUT;
using MDIncrementalRefreshBook = message_t<32>;

// Message MDIncrementalRefreshDailyStatistics
template<> struct group_element_t<33, 0> {
    using dimension = groupSize;
    PRICENULL _MDEntryPx; ///< Market Data entry price 0
    Int32NULL _MDEntrySize; ///< Market Data entry size 8
    Int32 _SecurityID; ///< Security ID  12
    uInt32 _RptSeq; ///< Market Data entry sequence number per instrument update 16
    LocalMktDate _TradingReferenceDate; ///< Indicates trade session date corresponding to a statistic entry 20
    SettlPriceType _SettlPriceType; ///< Bitmap field of eight Boolean type indicators representing settlement price type 22
    MDUpdateAction _MDUpdateAction; ///< Market Data update action 23
    MDEntryTypeDailyStatistics _MDEntryType; ///< Market Data entry type 24
    char padding[7];
} EXACT_LAYOUT;
using MDEntries_m33 = group_element_t<33, 0>;
template<> struct message_t<33> {
    uInt64 _TransactTime; ///< Start of event processing time in number of nanoseconds since Unix epoch 0
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 8
    char padding[2];
} EXACT_LAYOUT;
using MDIncrementalRefreshDailyStatistics = message_t<33>;

// Message MDIncrementalRefreshLimitsBanding
template<> struct group_element_t<34, 0> {
    using dimension = groupSize;
    PRICENULL _HighLimitPrice; ///< Upper price threshold for the instrument 0
    PRICENULL _LowLimitPrice; ///< Lower price threshold for the instrument 8
    PRICENULL _MaxPriceVariation; ///< Differential static value for price banding 16
    Int32 _SecurityID; ///< Security ID  24
    uInt32 _RptSeq; ///< MD Entry sequence number per instrument update 28
    constexpr static MDUpdateActionNew _MDUpdateAction = 0;
    constexpr static MDEntryTypeLimits _MDEntryType = 'g';
} EXACT_LAYOUT;
using MDEntries_m34 = group_element_t<34, 0>;
template<> struct message_t<34> {
    uInt64 _TransactTime; ///< Start of event processing time in number of nanoseconds since Unix epoch 0
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 8
    char padding[2];
} EXACT_LAYOUT;
using MDIncrementalRefreshLimitsBanding = message_t<34>;

// Message MDIncrementalRefreshSessionStatistics
template<> struct group_element_t<35, 0> {
    using dimension = groupSize;
    PRICE _MDEntryPx; ///< Market Data entry price 0
    Int32 _SecurityID; ///< Security ID  8
    uInt32 _RptSeq; ///< MD Entry sequence number per instrument update 12
    OpenCloseSettlFlag _OpenCloseSettlFlag; ///< Flag describing IOP and Open Price entries 16
    MDUpdateAction _MDUpdateAction; ///< Market Data update action  17
    MDEntryTypeStatistics _MDEntryType; ///< Market Data entry type    18
    char padding[5];
} EXACT_LAYOUT;
using MDEntries_m35 = group_element_t<35, 0>;
template<> struct message_t<35> {
    uInt64 _TransactTime; ///< Start of event processing time in number of nanoseconds since Unix epoch 0
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 8
    char padding[2];
} EXACT_LAYOUT;
using MDIncrementalRefreshSessionStatistics = message_t<35>;

// Message MDIncrementalRefreshTrade
template<> struct group_element_t<36, 0> {
    using dimension = groupSize;
    PRICE _MDEntryPx; ///< Trade price 0
    Int32 _MDEntrySize; ///< Trade quantity 8
    Int32 _SecurityID; ///< Security ID 12
    uInt32 _RptSeq; ///< Market Data entry sequence number per instrument update 16
    Int32NULL _NumberOfOrders; ///< Total number of real orders per instrument that participated in the trade 20
    Int32 _TradeID; ///< Unique Trade ID per instrument and Trading Date 24
    AggressorSide _AggressorSide; ///< Indicates aggressor side in the trade, if value is 0 then there is no aggressor 28
    MDUpdateAction _MDUpdateAction; ///< Market Data update action 29
    constexpr static MDEntryTypeTrade _MDEntryType = '2';
    char padding[2];
} EXACT_LAYOUT;
using MDEntries_m36 = group_element_t<36, 0>;
template<> struct message_t<36> {
    uInt64 _TransactTime; ///< Start of event processing time in number of nanoseconds since Unix epoch 0
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 8
    char padding[2];
} EXACT_LAYOUT;
using MDIncrementalRefreshTrade = message_t<36>;

// Message MDIncrementalRefreshVolume
template<> struct group_element_t<37, 0> {
    using dimension = groupSize;
    Int32 _MDEntrySize; ///< Cumulative traded volume 0
    Int32 _SecurityID; ///< Security ID 4
    uInt32 _RptSeq; ///< Market Data entry sequence number per instrument update 8
    MDUpdateAction _MDUpdateAction; ///< Market Data update action 12
    constexpr static MDEntryTypeVol _MDEntryType = 'e';
    char padding[3];
} EXACT_LAYOUT;
using MDEntries_m37 = group_element_t<37, 0>;
template<> struct message_t<37> {
    uInt64 _TransactTime; ///< Start of event processing time in number of nanoseconds since Unix epoch 0
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 8
    char padding[2];
} EXACT_LAYOUT;
using MDIncrementalRefreshVolume = message_t<37>;

// Message SnapshotFullRefresh
template<> struct group_element_t<38, 0> {
    using dimension = groupSize;
    PRICENULL _MDEntryPx; ///< Market Data entry price 0
    Int32NULL _MDEntrySize; ///< Market Data entry quantity 8
    Int32NULL _NumberOfOrders; ///< Aggregate number of orders at the given price level 12
    Int8NULL _MDPriceLevel; ///< Aggregate book position 16
    LocalMktDate _TradingReferenceDate; ///< Indicates the date of trade session corresponding to a statistic entry 17
    OpenCloseSettlFlag _OpenCloseSettlFlag; ///< Flag describing  Open Price entry 19
    SettlPriceType _SettlPriceType; ///< Bitmap field of eight Boolean type indicators representing settlement price type 20
    MDEntryType _MDEntryType; ///< Market Data entry type 21
} EXACT_LAYOUT;
using MDEntries_m38 = group_element_t<38, 0>;
template<> struct message_t<38> {
    uInt32 _LastMsgSeqNumProcessed; ///< Sequence number of the last Incremental feed packet processed. This value is used to synchronize the snapshot loop with the real-time feed 0
    uInt32 _TotNumReports; ///< Total number of messages replayed in the loop 4
    Int32 _SecurityID; ///< Security ID 8
    uInt32 _RptSeq; ///< Sequence number of the last Market Data entry processed for the instrument 12
    uInt64 _TransactTime; ///< Timestamp of the last event security participated in, sent as number of nanoseconds since Unix epoch 16
    uInt64 _LastUpdateTime; ///< UTC Date and time of last Security Definition add, update or delete on a given Market Data channel 24
    LocalMktDate _TradeDate; ///< Trade session date sent as number of days since Unix epoch 32
    SecurityTradingStatus _MDSecurityTradingStatus; ///< Identifies the current trading state of the instrument 34
    PRICENULL _HighLimitPrice; ///< Upper price threshold for the instrument 35
    PRICENULL _LowLimitPrice; ///< Lower price threshold for the instrument 43
    PRICENULL _MaxPriceVariation; ///< Differential value for price banding 51
} EXACT_LAYOUT;
using SnapshotFullRefresh = message_t<38>;

// Message QuoteRequest
template<> struct group_element_t<39, 0> {
    using dimension = groupSize;
    Symbol _Symbol; ///< Instrument Name or Symbol 0
    Int32 _SecurityID; ///< Security ID 20
    Int32NULL _OrderQty; ///< Quantity requested 24
    Int8 _QuoteType; ///< Type of quote requested 28
    Int8NULL _Side; ///< Side requested 29
    char padding[2];
} EXACT_LAYOUT;
using RelatedSym_m39 = group_element_t<39, 0>;
template<> struct message_t<39> {
    uInt64 _TransactTime; ///< Start of event processing time in number of nanoseconds since Unix epoch 0
    QuoteReqId _QuoteReqID; ///< Quote Request ID defined by the exchange 8
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 31
    char padding[3];
} EXACT_LAYOUT;
using QuoteRequest = message_t<39>;

// Message MDInstrumentDefinitionOption
template<> struct group_element_t<41, 0> {
    using dimension = groupSize;
    EventType _EventType; ///< Code to represent the type of event 0
    uInt64 _EventTime; ///< Date and Time of instument Activation or Expiration event sent as number of nanoseconds since Unix epoch 1
} EXACT_LAYOUT;
using Events_m41 = group_element_t<41, 0>;
template<> struct group_element_t<41, 1> {
    using dimension = groupSize;
    MDFeedType _MDFeedType; ///< Describes a class of service for a given data feed. GBX- Real Book, GBI-Implied Book 0
    Int8 _MarketDepth; ///< Book depth 3
} EXACT_LAYOUT;
using MDFeedTypes_m41 = group_element_t<41, 1>;
template<> struct group_element_t<41, 2> {
    using dimension = groupSize;
    constexpr static InstAttribType _InstAttribType = 24;
    InstAttribValue _InstAttribValue; ///< Bitmap field of 32 Boolean type Instrument eligibility flags 0
} EXACT_LAYOUT;
using InstAttrib_m41 = group_element_t<41, 2>;
template<> struct group_element_t<41, 3> {
    using dimension = groupSize;
    Int8 _LotType; ///< This tag is required to interpret the value in tag 1231-MinLotSize 0
    DecimalQty _MinLotSize; ///< Minimum quantity accepted for order entry. If tag 1093-LotType=4, this value is the minimum quantity for order entry expressed in the applicable units, specified in tag 996-UnitOfMeasure, e.g. megawatts 1
} EXACT_LAYOUT;
using LotTypeRules_m41 = group_element_t<41, 3>;
template<> struct group_element_t<41, 4> {
    using dimension = groupSize;
    Int32 _UnderlyingSecurityID; ///< Unique Instrument ID as qualified by the exchange per tag 305-UnderlyingSecurityIDSource 0
    constexpr static SecurityIDSource _UnderlyingSecurityIDSource = '8';
    UnderlyingSymbol _UnderlyingSymbol; ///< Underlying Instrument Symbol (Contract Name) 4
} EXACT_LAYOUT;
using Underlyings_m41 = group_element_t<41, 4>;
template<> struct message_t<41> {
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 0
    uInt32NULL _TotNumReports; ///< Total number of instruments in the Replay loop. Used on Replay Feed only  1
    SecurityUpdateAction _SecurityUpdateAction; ///< Last Security update action on Incremental feed, 'D' or 'M' is used when a mid-week deletion or modification (i.e. extension) occurs 5
    uInt64 _LastUpdateTime; ///< Timestamp of when the instrument was last added, modified or deleted 6
    SecurityTradingStatus _MDSecurityTradingStatus; ///< Identifies the current state of the instrument. The data is available in the Instrument Replay feed only  14
    Int16 _ApplID; ///< The channel ID as defined in the XML Configuration file 15
    uInt8 _MarketSegmentID; ///< Identifies the market segment, populated for all CME Globex instruments 17
    uInt8 _UnderlyingProduct; ///< Indicates the product complex 18
    SecurityExchange _SecurityExchange; ///< Exchange used to identify a security 19
    SecurityGroup _SecurityGroup; ///< Security Group Code  23
    Asset _Asset; ///< The underlying asset code also known as Product Code 29
    Symbol _Symbol; ///< Instrument Name or Symbol. Previously used as Instrument Group Code  35
    Int32 _SecurityID; ///< Unique Instrument ID 55
    constexpr static SecurityIDSource _SecurityIDSource = '8';
    SecurityType _SecurityType; ///< Security Type 59
    CFICode _CFICode; ///< ISO standard instrument categorization code 65
    PutOrCall _PutOrCall; ///< Indicates whether an option instrument is a put or call 71
    MaturityMonthYear _MaturityMonthYear; ///< This field provides the actual calendar date for contract maturity 72
    Currency _Currency; ///< Identifies currency used for price 77
    PRICENULL _StrikePrice; ///< Strike Price for an option instrument 80
    Currency _StrikeCurrency; ///< Currency in which the StrikePrice is denominated 88
    Currency _SettlCurrency; ///< Identifies currency used for settlement, if different from trade price currency 91
    PRICENULL _MinCabPrice; ///< Defines cabinet price for outright options products 94
    CHAR _MatchAlgorithm; ///< Matching algorithm 102
    uInt32 _MinTradeVol; ///< The minimum trading volume for a security. 103
    uInt32 _MaxTradeVol; ///< The maximum trading volume for a security. 107
    PRICENULL _MinPriceIncrement; ///< Minimum constant tick for the instrument 111
    PRICENULL _MinPriceIncrementAmount; ///< Monetary value equivalent to the minimum price fluctuation 119
    FLOAT _DisplayFactor; ///< Contains the multiplier to convert the CME Globex display price to the conventional price 127
    Int8NULL _TickRule; ///< VTT code referencing variable tick table  135
    uInt8NULL _MainFraction; ///< Price Denominator of Main Fraction 136
    uInt8NULL _SubFraction; ///< Price Denominator of Sub Fraction 137
    uInt8NULL _PriceDisplayFormat; ///< Number of decimals in fractional display price 138
    UnitOfMeasure _UnitOfMeasure; ///< Unit of measure for the products' original contract size. This will be populated for all products listed on CME Globex 139
    PRICENULL _UnitOfMeasureQty; ///< This field contains the contract size for each instrument. Used in combination with tag 996-UnitofMeasure 169
    PRICENULL _TradingReferencePrice; ///< Reference price - the most recently available Settlement whether it be Theoretical, Preliminary or a Final Settle of the session 177
    SettlPriceType _SettlPriceType; ///< Bitmap field of eight Boolean type indicators representing settlement price type 185
    Int32NULL _ClearedVolume; ///< The total cleared volume of instrument traded during the prior trading session 186
    Int32NULL _OpenInterestQty; ///< The total open interest for the market at the close of the prior trading session. 190
    PRICENULL _LowLimitPrice; ///< Allowable low limit price for the trading day  194
    PRICENULL _HighLimitPrice; ///< Allowable high limit price for the trading day 202
    UserDefinedInstrument _UserDefinedInstrument; ///< User-defined instruments flag 210
    LocalMktDate _TradingReferenceDate; ///< Indicates session date corresponding to the settlement price in tag 1150-TradingReferencePrice 211
} EXACT_LAYOUT;
using MDInstrumentDefinitionOption = message_t<41>;

// Message MDIncrementalRefreshTradeSummary
template<> struct group_element_t<42, 0> {
    using dimension = groupSize;
    PRICE _MDEntryPx; ///< Trade price 0
    Int32 _MDEntrySize; ///< Consolidated trade quantity 8
    Int32 _SecurityID; ///< Security ID as defined by CME 12
    uInt32 _RptSeq; ///< Sequence number per instrument update 16
    Int32NULL _NumberOfOrders; ///< The total number of real orders per instrument that participated in a match step within a match event 20
    AggressorSide _AggressorSide; ///< Indicates which side is the aggressor or if there is no aggressor 24
    MDUpdateAction _MDUpdateAction; ///< Market Data update action 25
    constexpr static MDEntryTypeTrade _MDEntryType = '2';
    char padding[6];
} EXACT_LAYOUT;
using MDEntries_m42 = group_element_t<42, 0>;
template<> struct group_element_t<42, 1> {
    using dimension = groupSize8Byte;
    uInt64 _OrderID; ///< Unique order identifier as assigned by the exchange 0
    Int32 _LastQty; ///< Quantity bought or sold on this last fill 8
    char padding[4];
} EXACT_LAYOUT;
using OrderIDEntries_m42 = group_element_t<42, 1>;
template<> struct message_t<42> {
    uInt64 _TransactTime; ///< Start of event processing time in number of nanoseconds since Unix epoch 0
    MatchEventIndicator _MatchEventIndicator; ///< Bitmap field of eight Boolean type indicators reflecting the end of updates for a given Globex event 8
    char padding[2];
} EXACT_LAYOUT;
using MDIncrementalRefreshTradeSummary = message_t<42>;

inline bool valid_id(int id) noexcept {
    switch(id) {
        case 4: // ChannelReset4
        case 12: // AdminHeartbeat12
        case 15: // AdminLogin15
        case 16: // AdminLogout16
        case 27: // MDInstrumentDefinitionFuture27
        case 29: // MDInstrumentDefinitionSpread29
        case 30: // SecurityStatus30
        case 32: // MDIncrementalRefreshBook32
        case 33: // MDIncrementalRefreshDailyStatistics33
        case 34: // MDIncrementalRefreshLimitsBanding34
        case 35: // MDIncrementalRefreshSessionStatistics35
        case 36: // MDIncrementalRefreshTrade36
        case 37: // MDIncrementalRefreshVolume37
        case 38: // SnapshotFullRefresh38
        case 39: // QuoteRequest39
        case 41: // MDInstrumentDefinitionOption41
        case 42: // MDIncrementalRefreshTradeSummary42
            return true;
    }
    return false;
}

#ifdef MDP3_VALIDATE_STRUCTURES
static_assert(2 == sizeof(MDEntries_m4), "MDEntries_m4 fails specified size of 2");
static_assert(9 == sizeof(Events_m27), "Events_m27 fails specified size of 9");
static_assert(4 == sizeof(MDFeedTypes_m27), "MDFeedTypes_m27 fails specified size of 4");
static_assert(4 == sizeof(InstAttrib_m27), "InstAttrib_m27 fails specified size of 4");
static_assert(5 == sizeof(LotTypeRules_m27), "LotTypeRules_m27 fails specified size of 5");
static_assert(9 == sizeof(Events_m29), "Events_m29 fails specified size of 9");
static_assert(4 == sizeof(MDFeedTypes_m29), "MDFeedTypes_m29 fails specified size of 4");
static_assert(4 == sizeof(InstAttrib_m29), "InstAttrib_m29 fails specified size of 4");
static_assert(5 == sizeof(LotTypeRules_m29), "LotTypeRules_m29 fails specified size of 5");
static_assert(18 == sizeof(Legs_m29), "Legs_m29 fails specified size of 18");
static_assert(32 == sizeof(MDEntries_m32), "MDEntries_m32 fails specified size of 32");
static_assert(32 == sizeof(MDEntries_m33), "MDEntries_m33 fails specified size of 32");
static_assert(32 == sizeof(MDEntries_m34), "MDEntries_m34 fails specified size of 32");
static_assert(24 == sizeof(MDEntries_m35), "MDEntries_m35 fails specified size of 24");
static_assert(32 == sizeof(MDEntries_m36), "MDEntries_m36 fails specified size of 32");
static_assert(16 == sizeof(MDEntries_m37), "MDEntries_m37 fails specified size of 16");
static_assert(22 == sizeof(MDEntries_m38), "MDEntries_m38 fails specified size of 22");
static_assert(32 == sizeof(RelatedSym_m39), "RelatedSym_m39 fails specified size of 32");
static_assert(9 == sizeof(Events_m41), "Events_m41 fails specified size of 9");
static_assert(4 == sizeof(MDFeedTypes_m41), "MDFeedTypes_m41 fails specified size of 4");
static_assert(4 == sizeof(InstAttrib_m41), "InstAttrib_m41 fails specified size of 4");
static_assert(5 == sizeof(LotTypeRules_m41), "LotTypeRules_m41 fails specified size of 5");
static_assert(24 == sizeof(Underlyings_m41), "Underlyings_m41 fails specified size of 24");
static_assert(32 == sizeof(MDEntries_m42), "MDEntries_m42 fails specified size of 32");
static_assert(16 == sizeof(OrderIDEntries_m42), "OrderIDEntries_m42 fails specified size of 16");
#endif

template<> struct Identifiers<AggressorSide> {
    static const char *identifier(AggressorSide value) {
        switch(value) {
            case AggressorSide::NoAggressor: return "NoAggressor";
            case AggressorSide::Buy: return "Buy";
            case AggressorSide::Sell: return "Sell";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<EventType> {
    static const char *identifier(EventType value) {
        switch(value) {
            case EventType::Activation: return "Activation";
            case EventType::LastEligibleTradeDate: return "LastEligibleTradeDate";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<HaltReason> {
    static const char *identifier(HaltReason value) {
        switch(value) {
            case HaltReason::GroupSchedule: return "GroupSchedule";
            case HaltReason::SurveillanceIntervention: return "SurveillanceIntervention";
            case HaltReason::MarketEvent: return "MarketEvent";
            case HaltReason::InstrumentActivation: return "InstrumentActivation";
            case HaltReason::InstrumentExpiration: return "InstrumentExpiration";
            case HaltReason::Unknown: return "Unknown";
            case HaltReason::RecoveryInProcess: return "RecoveryInProcess";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<LegSide> {
    static const char *identifier(LegSide value) {
        switch(value) {
            case LegSide::BuySide: return "BuySide";
            case LegSide::SellSide: return "SellSide";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<MDEntryType> {
    static const char *identifier(MDEntryType value) {
        switch(value) {
            case MDEntryType::Bid: return "Bid";
            case MDEntryType::Offer: return "Offer";
            case MDEntryType::Trade: return "Trade";
            case MDEntryType::OpenPrice: return "OpenPrice";
            case MDEntryType::SettlementPrice: return "SettlementPrice";
            case MDEntryType::TradingSessionHighPrice: return "TradingSessionHighPrice";
            case MDEntryType::TradingSessionLowPrice: return "TradingSessionLowPrice";
            case MDEntryType::ClearedVolume: return "ClearedVolume";
            case MDEntryType::OpenInterest: return "OpenInterest";
            case MDEntryType::ImpliedBid: return "ImpliedBid";
            case MDEntryType::ImpliedOffer: return "ImpliedOffer";
            case MDEntryType::BookReset: return "BookReset";
            case MDEntryType::SessionHighBid: return "SessionHighBid";
            case MDEntryType::SessionLowOffer: return "SessionLowOffer";
            case MDEntryType::FixingPrice: return "FixingPrice";
            case MDEntryType::ElectronicVolume: return "ElectronicVolume";
            case MDEntryType::ThresholdLimitsandPriceBandVariation: return "ThresholdLimitsandPriceBandVariation";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<MDEntryTypeBook> {
    static const char *identifier(MDEntryTypeBook value) {
        switch(value) {
            case MDEntryTypeBook::Bid: return "Bid";
            case MDEntryTypeBook::Offer: return "Offer";
            case MDEntryTypeBook::ImpliedBid: return "ImpliedBid";
            case MDEntryTypeBook::ImpliedOffer: return "ImpliedOffer";
            case MDEntryTypeBook::BookReset: return "BookReset";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<MDEntryTypeDailyStatistics> {
    static const char *identifier(MDEntryTypeDailyStatistics value) {
        switch(value) {
            case MDEntryTypeDailyStatistics::SettlementPrice: return "SettlementPrice";
            case MDEntryTypeDailyStatistics::ClearedVolume: return "ClearedVolume";
            case MDEntryTypeDailyStatistics::OpenInterest: return "OpenInterest";
            case MDEntryTypeDailyStatistics::FixingPrice: return "FixingPrice";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<MDEntryTypeStatistics> {
    static const char *identifier(MDEntryTypeStatistics value) {
        switch(value) {
            case MDEntryTypeStatistics::OpenPrice: return "OpenPrice";
            case MDEntryTypeStatistics::HighTrade: return "HighTrade";
            case MDEntryTypeStatistics::LowTrade: return "LowTrade";
            case MDEntryTypeStatistics::HighestBid: return "HighestBid";
            case MDEntryTypeStatistics::LowestOffer: return "LowestOffer";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<MDUpdateAction> {
    static const char *identifier(MDUpdateAction value) {
        switch(value) {
            case MDUpdateAction::New: return "New";
            case MDUpdateAction::Change: return "Change";
            case MDUpdateAction::Delete: return "Delete";
            case MDUpdateAction::DeleteThru: return "DeleteThru";
            case MDUpdateAction::DeleteFrom: return "DeleteFrom";
            case MDUpdateAction::Overlay: return "Overlay";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<OpenCloseSettlFlag> {
    static const char *identifier(OpenCloseSettlFlag value) {
        switch(value) {
            case OpenCloseSettlFlag::DailyOpenPrice: return "DailyOpenPrice";
            case OpenCloseSettlFlag::IndicativeOpeningPrice: return "IndicativeOpeningPrice";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<PutOrCall> {
    static const char *identifier(PutOrCall value) {
        switch(value) {
            case PutOrCall::Put: return "Put";
            case PutOrCall::Call: return "Call";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<SecurityTradingEvent> {
    static const char *identifier(SecurityTradingEvent value) {
        switch(value) {
            case SecurityTradingEvent::NoEvent: return "NoEvent";
            case SecurityTradingEvent::NoCancel: return "NoCancel";
            case SecurityTradingEvent::ResetStatistics: return "ResetStatistics";
            case SecurityTradingEvent::ImpliedMatchingON: return "ImpliedMatchingON";
            case SecurityTradingEvent::ImpliedMatchingOFF: return "ImpliedMatchingOFF";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<SecurityTradingStatus> {
    static const char *identifier(SecurityTradingStatus value) {
        switch(value) {
            case SecurityTradingStatus::TradingHalt: return "TradingHalt";
            case SecurityTradingStatus::Close: return "Close";
            case SecurityTradingStatus::NewPriceIndication: return "NewPriceIndication";
            case SecurityTradingStatus::ReadyToTrade: return "ReadyToTrade";
            case SecurityTradingStatus::NotAvailableForTrading: return "NotAvailableForTrading";
            case SecurityTradingStatus::UnknownorInvalid: return "UnknownorInvalid";
            case SecurityTradingStatus::PreOpen: return "PreOpen";
            case SecurityTradingStatus::PreCross: return "PreCross";
            case SecurityTradingStatus::Cross: return "Cross";
            case SecurityTradingStatus::PostClose: return "PostClose";
            case SecurityTradingStatus::NoChange: return "NoChange";
            default: return nullptr;
        }
    }
};

template<> struct Identifiers<SecurityUpdateAction> {
    static const char *identifier(SecurityUpdateAction value) {
        switch(value) {
            case SecurityUpdateAction::Add: return "Add";
            case SecurityUpdateAction::Delete: return "Delete";
            case SecurityUpdateAction::Modify: return "Modify";
            default: return nullptr;
        }
    }
};

template<> struct Members<DecimalQty> {
    using type = Pack<
        Member<decltype(&DecimalQty::mantissa), &DecimalQty::mantissa>
    >;
    static const char **names() {
        static const char *rv[] = { "mantissa" };
        return rv;
    }
    static const char *name() { return "DecimalQty"; }
};

template<> struct Members<FLOAT> {
    using type = Pack<
        Member<decltype(&FLOAT::mantissa), &FLOAT::mantissa>
    >;
    static const char **names() {
        static const char *rv[] = { "mantissa" };
        return rv;
    }
    static const char *name() { return "FLOAT"; }
};

template<> struct Members<MaturityMonthYear> {
    using type = Pack<
        Member<decltype(&MaturityMonthYear::year), &MaturityMonthYear::year>,
        Member<decltype(&MaturityMonthYear::month), &MaturityMonthYear::month>,
        Member<decltype(&MaturityMonthYear::day), &MaturityMonthYear::day>,
        Member<decltype(&MaturityMonthYear::week), &MaturityMonthYear::week>
    >;
    static const char **names() {
        static const char *rv[] = { "year", "month", "day", "week" };
        return rv;
    }
    static const char *name() { return "MaturityMonthYear"; }
};

template<> struct Members<PRICE> {
    using type = Pack<
        Member<decltype(&PRICE::mantissa), &PRICE::mantissa>
    >;
    static const char **names() {
        static const char *rv[] = { "mantissa" };
        return rv;
    }
    static const char *name() { return "PRICE"; }
};

template<> struct Members<PRICENULL> {
    using type = Pack<
        Member<decltype(&PRICENULL::mantissa), &PRICENULL::mantissa>
    >;
    static const char **names() {
        static const char *rv[] = { "mantissa" };
        return rv;
    }
    static const char *name() { return "PRICENULL"; }
};

template<> struct Members<groupSize> {
    using type = Pack<
        Member<decltype(&groupSize::blockLength), &groupSize::blockLength>,
        Member<decltype(&groupSize::numInGroup), &groupSize::numInGroup>
    >;
    static const char **names() {
        static const char *rv[] = { "blockLength", "numInGroup" };
        return rv;
    }
    static const char *name() { return "groupSize"; }
};

template<> struct Members<groupSize8Byte> {
    using type = Pack<
        Member<decltype(&groupSize8Byte::blockLength), &groupSize8Byte::blockLength>,
        Member<decltype(&groupSize8Byte::numInGroup), &groupSize8Byte::numInGroup>
    >;
    static const char **names() {
        static const char *rv[] = { "blockLength", "numInGroup" };
        return rv;
    }
    static const char *name() { return "groupSize8Byte"; }
};

template<> struct Members<groupSizeEncoding> {
    using type = Pack<
        Member<decltype(&groupSizeEncoding::blockLength), &groupSizeEncoding::blockLength>,
        Member<decltype(&groupSizeEncoding::numInGroup), &groupSizeEncoding::numInGroup>
    >;
    static const char **names() {
        static const char *rv[] = { "blockLength", "numInGroup" };
        return rv;
    }
    static const char *name() { return "groupSizeEncoding"; }
};

template<> struct Members<messageHeader> {
    using type = Pack<
        Member<decltype(&messageHeader::blockLength), &messageHeader::blockLength>,
        Member<decltype(&messageHeader::templateId), &messageHeader::templateId>,
        Member<decltype(&messageHeader::schemaId), &messageHeader::schemaId>,
        Member<decltype(&messageHeader::version), &messageHeader::version>
    >;
    static const char **names() {
        static const char *rv[] = { "blockLength", "templateId", "schemaId", "version" };
        return rv;
    }
    static const char *name() { return "messageHeader"; }
};

template<> struct Members<MDEntries_m4> {
    using type = Pack<
        Member<decltype(&MDEntries_m4::_ApplID), &MDEntries_m4::_ApplID>
    >;
    static const char **names() {
        static const char *rv[] = { "_ApplID" };
        return rv;
    }
    static const char *name() { return "MDEntries_m4"; }
};

template<> struct Members<ChannelReset> {
    using type = Pack<
        Member<decltype(&ChannelReset::_TransactTime), &ChannelReset::_TransactTime>,
        Member<decltype(&ChannelReset::_MatchEventIndicator), &ChannelReset::_MatchEventIndicator>
    >;
    static const char **names() {
        static const char *rv[] = { "_TransactTime", "_MatchEventIndicator" };
        return rv;
    }
    static const char *name() { return "ChannelReset"; }
};

template<> struct Members<AdminHeartbeat> {
    using type = Pack<

    >;
    static const char **names() {
        static const char *rv[] = {  };
        return rv;
    }
    static const char *name() { return "AdminHeartbeat"; }
};

template<> struct Members<AdminLogin> {
    using type = Pack<
        Member<decltype(&AdminLogin::_HeartBtInt), &AdminLogin::_HeartBtInt>
    >;
    static const char **names() {
        static const char *rv[] = { "_HeartBtInt" };
        return rv;
    }
    static const char *name() { return "AdminLogin"; }
};

template<> struct Members<AdminLogout> {
    using type = Pack<
        Member<decltype(&AdminLogout::_Text), &AdminLogout::_Text>
    >;
    static const char **names() {
        static const char *rv[] = { "_Text" };
        return rv;
    }
    static const char *name() { return "AdminLogout"; }
};

template<> struct Members<Events_m27> {
    using type = Pack<
        Member<decltype(&Events_m27::_EventType), &Events_m27::_EventType>,
        Member<decltype(&Events_m27::_EventTime), &Events_m27::_EventTime>
    >;
    static const char **names() {
        static const char *rv[] = { "_EventType", "_EventTime" };
        return rv;
    }
    static const char *name() { return "Events_m27"; }
};

template<> struct Members<MDFeedTypes_m27> {
    using type = Pack<
        Member<decltype(&MDFeedTypes_m27::_MDFeedType), &MDFeedTypes_m27::_MDFeedType>,
        Member<decltype(&MDFeedTypes_m27::_MarketDepth), &MDFeedTypes_m27::_MarketDepth>
    >;
    static const char **names() {
        static const char *rv[] = { "_MDFeedType", "_MarketDepth" };
        return rv;
    }
    static const char *name() { return "MDFeedTypes_m27"; }
};

template<> struct Members<InstAttrib_m27> {
    using type = Pack<
        Member<decltype(&InstAttrib_m27::_InstAttribValue), &InstAttrib_m27::_InstAttribValue>
    >;
    static const char **names() {
        static const char *rv[] = { "_InstAttribValue" };
        return rv;
    }
    static const char *name() { return "InstAttrib_m27"; }
};

template<> struct Members<LotTypeRules_m27> {
    using type = Pack<
        Member<decltype(&LotTypeRules_m27::_LotType), &LotTypeRules_m27::_LotType>,
        Member<decltype(&LotTypeRules_m27::_MinLotSize), &LotTypeRules_m27::_MinLotSize>
    >;
    static const char **names() {
        static const char *rv[] = { "_LotType", "_MinLotSize" };
        return rv;
    }
    static const char *name() { return "LotTypeRules_m27"; }
};

template<> struct Members<MDInstrumentDefinitionFuture> {
    using type = Pack<
        Member<decltype(&MDInstrumentDefinitionFuture::_MatchEventIndicator), &MDInstrumentDefinitionFuture::_MatchEventIndicator>,
        Member<decltype(&MDInstrumentDefinitionFuture::_TotNumReports), &MDInstrumentDefinitionFuture::_TotNumReports>,
        Member<decltype(&MDInstrumentDefinitionFuture::_SecurityUpdateAction), &MDInstrumentDefinitionFuture::_SecurityUpdateAction>,
        Member<decltype(&MDInstrumentDefinitionFuture::_LastUpdateTime), &MDInstrumentDefinitionFuture::_LastUpdateTime>,
        Member<decltype(&MDInstrumentDefinitionFuture::_MDSecurityTradingStatus), &MDInstrumentDefinitionFuture::_MDSecurityTradingStatus>,
        Member<decltype(&MDInstrumentDefinitionFuture::_ApplID), &MDInstrumentDefinitionFuture::_ApplID>,
        Member<decltype(&MDInstrumentDefinitionFuture::_MarketSegmentID), &MDInstrumentDefinitionFuture::_MarketSegmentID>,
        Member<decltype(&MDInstrumentDefinitionFuture::_UnderlyingProduct), &MDInstrumentDefinitionFuture::_UnderlyingProduct>,
        Member<decltype(&MDInstrumentDefinitionFuture::_SecurityExchange), &MDInstrumentDefinitionFuture::_SecurityExchange>,
        Member<decltype(&MDInstrumentDefinitionFuture::_SecurityGroup), &MDInstrumentDefinitionFuture::_SecurityGroup>,
        Member<decltype(&MDInstrumentDefinitionFuture::_Asset), &MDInstrumentDefinitionFuture::_Asset>,
        Member<decltype(&MDInstrumentDefinitionFuture::_Symbol), &MDInstrumentDefinitionFuture::_Symbol>,
        Member<decltype(&MDInstrumentDefinitionFuture::_SecurityID), &MDInstrumentDefinitionFuture::_SecurityID>,
        Member<decltype(&MDInstrumentDefinitionFuture::_SecurityType), &MDInstrumentDefinitionFuture::_SecurityType>,
        Member<decltype(&MDInstrumentDefinitionFuture::_CFICode), &MDInstrumentDefinitionFuture::_CFICode>,
        Member<decltype(&MDInstrumentDefinitionFuture::_MaturityMonthYear), &MDInstrumentDefinitionFuture::_MaturityMonthYear>,
        Member<decltype(&MDInstrumentDefinitionFuture::_Currency), &MDInstrumentDefinitionFuture::_Currency>,
        Member<decltype(&MDInstrumentDefinitionFuture::_SettlCurrency), &MDInstrumentDefinitionFuture::_SettlCurrency>,
        Member<decltype(&MDInstrumentDefinitionFuture::_MatchAlgorithm), &MDInstrumentDefinitionFuture::_MatchAlgorithm>,
        Member<decltype(&MDInstrumentDefinitionFuture::_MinTradeVol), &MDInstrumentDefinitionFuture::_MinTradeVol>,
        Member<decltype(&MDInstrumentDefinitionFuture::_MaxTradeVol), &MDInstrumentDefinitionFuture::_MaxTradeVol>,
        Member<decltype(&MDInstrumentDefinitionFuture::_MinPriceIncrement), &MDInstrumentDefinitionFuture::_MinPriceIncrement>,
        Member<decltype(&MDInstrumentDefinitionFuture::_DisplayFactor), &MDInstrumentDefinitionFuture::_DisplayFactor>,
        Member<decltype(&MDInstrumentDefinitionFuture::_MainFraction), &MDInstrumentDefinitionFuture::_MainFraction>,
        Member<decltype(&MDInstrumentDefinitionFuture::_SubFraction), &MDInstrumentDefinitionFuture::_SubFraction>,
        Member<decltype(&MDInstrumentDefinitionFuture::_PriceDisplayFormat), &MDInstrumentDefinitionFuture::_PriceDisplayFormat>,
        Member<decltype(&MDInstrumentDefinitionFuture::_UnitOfMeasure), &MDInstrumentDefinitionFuture::_UnitOfMeasure>,
        Member<decltype(&MDInstrumentDefinitionFuture::_UnitOfMeasureQty), &MDInstrumentDefinitionFuture::_UnitOfMeasureQty>,
        Member<decltype(&MDInstrumentDefinitionFuture::_TradingReferencePrice), &MDInstrumentDefinitionFuture::_TradingReferencePrice>,
        Member<decltype(&MDInstrumentDefinitionFuture::_SettlPriceType), &MDInstrumentDefinitionFuture::_SettlPriceType>,
        Member<decltype(&MDInstrumentDefinitionFuture::_OpenInterestQty), &MDInstrumentDefinitionFuture::_OpenInterestQty>,
        Member<decltype(&MDInstrumentDefinitionFuture::_ClearedVolume), &MDInstrumentDefinitionFuture::_ClearedVolume>,
        Member<decltype(&MDInstrumentDefinitionFuture::_HighLimitPrice), &MDInstrumentDefinitionFuture::_HighLimitPrice>,
        Member<decltype(&MDInstrumentDefinitionFuture::_LowLimitPrice), &MDInstrumentDefinitionFuture::_LowLimitPrice>,
        Member<decltype(&MDInstrumentDefinitionFuture::_MaxPriceVariation), &MDInstrumentDefinitionFuture::_MaxPriceVariation>,
        Member<decltype(&MDInstrumentDefinitionFuture::_DecayQuantity), &MDInstrumentDefinitionFuture::_DecayQuantity>,
        Member<decltype(&MDInstrumentDefinitionFuture::_DecayStartDate), &MDInstrumentDefinitionFuture::_DecayStartDate>,
        Member<decltype(&MDInstrumentDefinitionFuture::_OriginalContractSize), &MDInstrumentDefinitionFuture::_OriginalContractSize>,
        Member<decltype(&MDInstrumentDefinitionFuture::_ContractMultiplier), &MDInstrumentDefinitionFuture::_ContractMultiplier>,
        Member<decltype(&MDInstrumentDefinitionFuture::_ContractMultiplierUnit), &MDInstrumentDefinitionFuture::_ContractMultiplierUnit>,
        Member<decltype(&MDInstrumentDefinitionFuture::_FlowScheduleType), &MDInstrumentDefinitionFuture::_FlowScheduleType>,
        Member<decltype(&MDInstrumentDefinitionFuture::_MinPriceIncrementAmount), &MDInstrumentDefinitionFuture::_MinPriceIncrementAmount>,
        Member<decltype(&MDInstrumentDefinitionFuture::_UserDefinedInstrument), &MDInstrumentDefinitionFuture::_UserDefinedInstrument>,
        Member<decltype(&MDInstrumentDefinitionFuture::_TradingReferenceDate), &MDInstrumentDefinitionFuture::_TradingReferenceDate>
    >;
    static const char **names() {
        static const char *rv[] = { "_MatchEventIndicator", "_TotNumReports", "_SecurityUpdateAction", "_LastUpdateTime", "_MDSecurityTradingStatus", "_ApplID", "_MarketSegmentID", "_UnderlyingProduct", "_SecurityExchange", "_SecurityGroup", "_Asset", "_Symbol", "_SecurityID", "_SecurityType", "_CFICode", "_MaturityMonthYear", "_Currency", "_SettlCurrency", "_MatchAlgorithm", "_MinTradeVol", "_MaxTradeVol", "_MinPriceIncrement", "_DisplayFactor", "_MainFraction", "_SubFraction", "_PriceDisplayFormat", "_UnitOfMeasure", "_UnitOfMeasureQty", "_TradingReferencePrice", "_SettlPriceType", "_OpenInterestQty", "_ClearedVolume", "_HighLimitPrice", "_LowLimitPrice", "_MaxPriceVariation", "_DecayQuantity", "_DecayStartDate", "_OriginalContractSize", "_ContractMultiplier", "_ContractMultiplierUnit", "_FlowScheduleType", "_MinPriceIncrementAmount", "_UserDefinedInstrument", "_TradingReferenceDate" };
        return rv;
    }
    static const char *name() { return "MDInstrumentDefinitionFuture"; }
};

template<> struct Members<Events_m29> {
    using type = Pack<
        Member<decltype(&Events_m29::_EventType), &Events_m29::_EventType>,
        Member<decltype(&Events_m29::_EventTime), &Events_m29::_EventTime>
    >;
    static const char **names() {
        static const char *rv[] = { "_EventType", "_EventTime" };
        return rv;
    }
    static const char *name() { return "Events_m29"; }
};

template<> struct Members<MDFeedTypes_m29> {
    using type = Pack<
        Member<decltype(&MDFeedTypes_m29::_MDFeedType), &MDFeedTypes_m29::_MDFeedType>,
        Member<decltype(&MDFeedTypes_m29::_MarketDepth), &MDFeedTypes_m29::_MarketDepth>
    >;
    static const char **names() {
        static const char *rv[] = { "_MDFeedType", "_MarketDepth" };
        return rv;
    }
    static const char *name() { return "MDFeedTypes_m29"; }
};

template<> struct Members<InstAttrib_m29> {
    using type = Pack<
        Member<decltype(&InstAttrib_m29::_InstAttribValue), &InstAttrib_m29::_InstAttribValue>
    >;
    static const char **names() {
        static const char *rv[] = { "_InstAttribValue" };
        return rv;
    }
    static const char *name() { return "InstAttrib_m29"; }
};

template<> struct Members<LotTypeRules_m29> {
    using type = Pack<
        Member<decltype(&LotTypeRules_m29::_LotType), &LotTypeRules_m29::_LotType>,
        Member<decltype(&LotTypeRules_m29::_MinLotSize), &LotTypeRules_m29::_MinLotSize>
    >;
    static const char **names() {
        static const char *rv[] = { "_LotType", "_MinLotSize" };
        return rv;
    }
    static const char *name() { return "LotTypeRules_m29"; }
};

template<> struct Members<Legs_m29> {
    using type = Pack<
        Member<decltype(&Legs_m29::_LegSecurityID), &Legs_m29::_LegSecurityID>,
        Member<decltype(&Legs_m29::_LegSide), &Legs_m29::_LegSide>,
        Member<decltype(&Legs_m29::_LegRatioQty), &Legs_m29::_LegRatioQty>,
        Member<decltype(&Legs_m29::_LegPrice), &Legs_m29::_LegPrice>,
        Member<decltype(&Legs_m29::_LegOptionDelta), &Legs_m29::_LegOptionDelta>
    >;
    static const char **names() {
        static const char *rv[] = { "_LegSecurityID", "_LegSide", "_LegRatioQty", "_LegPrice", "_LegOptionDelta" };
        return rv;
    }
    static const char *name() { return "Legs_m29"; }
};

template<> struct Members<MDInstrumentDefinitionSpread> {
    using type = Pack<
        Member<decltype(&MDInstrumentDefinitionSpread::_MatchEventIndicator), &MDInstrumentDefinitionSpread::_MatchEventIndicator>,
        Member<decltype(&MDInstrumentDefinitionSpread::_TotNumReports), &MDInstrumentDefinitionSpread::_TotNumReports>,
        Member<decltype(&MDInstrumentDefinitionSpread::_SecurityUpdateAction), &MDInstrumentDefinitionSpread::_SecurityUpdateAction>,
        Member<decltype(&MDInstrumentDefinitionSpread::_LastUpdateTime), &MDInstrumentDefinitionSpread::_LastUpdateTime>,
        Member<decltype(&MDInstrumentDefinitionSpread::_MDSecurityTradingStatus), &MDInstrumentDefinitionSpread::_MDSecurityTradingStatus>,
        Member<decltype(&MDInstrumentDefinitionSpread::_ApplID), &MDInstrumentDefinitionSpread::_ApplID>,
        Member<decltype(&MDInstrumentDefinitionSpread::_MarketSegmentID), &MDInstrumentDefinitionSpread::_MarketSegmentID>,
        Member<decltype(&MDInstrumentDefinitionSpread::_UnderlyingProduct), &MDInstrumentDefinitionSpread::_UnderlyingProduct>,
        Member<decltype(&MDInstrumentDefinitionSpread::_SecurityExchange), &MDInstrumentDefinitionSpread::_SecurityExchange>,
        Member<decltype(&MDInstrumentDefinitionSpread::_SecurityGroup), &MDInstrumentDefinitionSpread::_SecurityGroup>,
        Member<decltype(&MDInstrumentDefinitionSpread::_Asset), &MDInstrumentDefinitionSpread::_Asset>,
        Member<decltype(&MDInstrumentDefinitionSpread::_Symbol), &MDInstrumentDefinitionSpread::_Symbol>,
        Member<decltype(&MDInstrumentDefinitionSpread::_SecurityID), &MDInstrumentDefinitionSpread::_SecurityID>,
        Member<decltype(&MDInstrumentDefinitionSpread::_SecurityType), &MDInstrumentDefinitionSpread::_SecurityType>,
        Member<decltype(&MDInstrumentDefinitionSpread::_CFICode), &MDInstrumentDefinitionSpread::_CFICode>,
        Member<decltype(&MDInstrumentDefinitionSpread::_MaturityMonthYear), &MDInstrumentDefinitionSpread::_MaturityMonthYear>,
        Member<decltype(&MDInstrumentDefinitionSpread::_Currency), &MDInstrumentDefinitionSpread::_Currency>,
        Member<decltype(&MDInstrumentDefinitionSpread::_SecuritySubType), &MDInstrumentDefinitionSpread::_SecuritySubType>,
        Member<decltype(&MDInstrumentDefinitionSpread::_UserDefinedInstrument), &MDInstrumentDefinitionSpread::_UserDefinedInstrument>,
        Member<decltype(&MDInstrumentDefinitionSpread::_MatchAlgorithm), &MDInstrumentDefinitionSpread::_MatchAlgorithm>,
        Member<decltype(&MDInstrumentDefinitionSpread::_MinTradeVol), &MDInstrumentDefinitionSpread::_MinTradeVol>,
        Member<decltype(&MDInstrumentDefinitionSpread::_MaxTradeVol), &MDInstrumentDefinitionSpread::_MaxTradeVol>,
        Member<decltype(&MDInstrumentDefinitionSpread::_MinPriceIncrement), &MDInstrumentDefinitionSpread::_MinPriceIncrement>,
        Member<decltype(&MDInstrumentDefinitionSpread::_DisplayFactor), &MDInstrumentDefinitionSpread::_DisplayFactor>,
        Member<decltype(&MDInstrumentDefinitionSpread::_PriceDisplayFormat), &MDInstrumentDefinitionSpread::_PriceDisplayFormat>,
        Member<decltype(&MDInstrumentDefinitionSpread::_PriceRatio), &MDInstrumentDefinitionSpread::_PriceRatio>,
        Member<decltype(&MDInstrumentDefinitionSpread::_TickRule), &MDInstrumentDefinitionSpread::_TickRule>,
        Member<decltype(&MDInstrumentDefinitionSpread::_UnitOfMeasure), &MDInstrumentDefinitionSpread::_UnitOfMeasure>,
        Member<decltype(&MDInstrumentDefinitionSpread::_TradingReferencePrice), &MDInstrumentDefinitionSpread::_TradingReferencePrice>,
        Member<decltype(&MDInstrumentDefinitionSpread::_SettlPriceType), &MDInstrumentDefinitionSpread::_SettlPriceType>,
        Member<decltype(&MDInstrumentDefinitionSpread::_OpenInterestQty), &MDInstrumentDefinitionSpread::_OpenInterestQty>,
        Member<decltype(&MDInstrumentDefinitionSpread::_ClearedVolume), &MDInstrumentDefinitionSpread::_ClearedVolume>,
        Member<decltype(&MDInstrumentDefinitionSpread::_HighLimitPrice), &MDInstrumentDefinitionSpread::_HighLimitPrice>,
        Member<decltype(&MDInstrumentDefinitionSpread::_LowLimitPrice), &MDInstrumentDefinitionSpread::_LowLimitPrice>,
        Member<decltype(&MDInstrumentDefinitionSpread::_MaxPriceVariation), &MDInstrumentDefinitionSpread::_MaxPriceVariation>,
        Member<decltype(&MDInstrumentDefinitionSpread::_MainFraction), &MDInstrumentDefinitionSpread::_MainFraction>,
        Member<decltype(&MDInstrumentDefinitionSpread::_SubFraction), &MDInstrumentDefinitionSpread::_SubFraction>,
        Member<decltype(&MDInstrumentDefinitionSpread::_TradingReferenceDate), &MDInstrumentDefinitionSpread::_TradingReferenceDate>
    >;
    static const char **names() {
        static const char *rv[] = { "_MatchEventIndicator", "_TotNumReports", "_SecurityUpdateAction", "_LastUpdateTime", "_MDSecurityTradingStatus", "_ApplID", "_MarketSegmentID", "_UnderlyingProduct", "_SecurityExchange", "_SecurityGroup", "_Asset", "_Symbol", "_SecurityID", "_SecurityType", "_CFICode", "_MaturityMonthYear", "_Currency", "_SecuritySubType", "_UserDefinedInstrument", "_MatchAlgorithm", "_MinTradeVol", "_MaxTradeVol", "_MinPriceIncrement", "_DisplayFactor", "_PriceDisplayFormat", "_PriceRatio", "_TickRule", "_UnitOfMeasure", "_TradingReferencePrice", "_SettlPriceType", "_OpenInterestQty", "_ClearedVolume", "_HighLimitPrice", "_LowLimitPrice", "_MaxPriceVariation", "_MainFraction", "_SubFraction", "_TradingReferenceDate" };
        return rv;
    }
    static const char *name() { return "MDInstrumentDefinitionSpread"; }
};

template<> struct Members<SecurityStatus> {
    using type = Pack<
        Member<decltype(&SecurityStatus::_TransactTime), &SecurityStatus::_TransactTime>,
        Member<decltype(&SecurityStatus::_SecurityGroup), &SecurityStatus::_SecurityGroup>,
        Member<decltype(&SecurityStatus::_Asset), &SecurityStatus::_Asset>,
        Member<decltype(&SecurityStatus::_SecurityID), &SecurityStatus::_SecurityID>,
        Member<decltype(&SecurityStatus::_TradeDate), &SecurityStatus::_TradeDate>,
        Member<decltype(&SecurityStatus::_MatchEventIndicator), &SecurityStatus::_MatchEventIndicator>,
        Member<decltype(&SecurityStatus::_SecurityTradingStatus), &SecurityStatus::_SecurityTradingStatus>,
        Member<decltype(&SecurityStatus::_HaltReason), &SecurityStatus::_HaltReason>,
        Member<decltype(&SecurityStatus::_SecurityTradingEvent), &SecurityStatus::_SecurityTradingEvent>
    >;
    static const char **names() {
        static const char *rv[] = { "_TransactTime", "_SecurityGroup", "_Asset", "_SecurityID", "_TradeDate", "_MatchEventIndicator", "_SecurityTradingStatus", "_HaltReason", "_SecurityTradingEvent" };
        return rv;
    }
    static const char *name() { return "SecurityStatus"; }
};

template<> struct Members<MDEntries_m32> {
    using type = Pack<
        Member<decltype(&MDEntries_m32::_MDEntryPx), &MDEntries_m32::_MDEntryPx>,
        Member<decltype(&MDEntries_m32::_MDEntrySize), &MDEntries_m32::_MDEntrySize>,
        Member<decltype(&MDEntries_m32::_SecurityID), &MDEntries_m32::_SecurityID>,
        Member<decltype(&MDEntries_m32::_RptSeq), &MDEntries_m32::_RptSeq>,
        Member<decltype(&MDEntries_m32::_NumberOfOrders), &MDEntries_m32::_NumberOfOrders>,
        Member<decltype(&MDEntries_m32::_MDPriceLevel), &MDEntries_m32::_MDPriceLevel>,
        Member<decltype(&MDEntries_m32::_MDUpdateAction), &MDEntries_m32::_MDUpdateAction>,
        Member<decltype(&MDEntries_m32::_MDEntryType), &MDEntries_m32::_MDEntryType>
    >;
    static const char **names() {
        static const char *rv[] = { "_MDEntryPx", "_MDEntrySize", "_SecurityID", "_RptSeq", "_NumberOfOrders", "_MDPriceLevel", "_MDUpdateAction", "_MDEntryType" };
        return rv;
    }
    static const char *name() { return "MDEntries_m32"; }
};

template<> struct Members<MDIncrementalRefreshBook> {
    using type = Pack<
        Member<decltype(&MDIncrementalRefreshBook::_TransactTime), &MDIncrementalRefreshBook::_TransactTime>,
        Member<decltype(&MDIncrementalRefreshBook::_MatchEventIndicator), &MDIncrementalRefreshBook::_MatchEventIndicator>
    >;
    static const char **names() {
        static const char *rv[] = { "_TransactTime", "_MatchEventIndicator" };
        return rv;
    }
    static const char *name() { return "MDIncrementalRefreshBook"; }
};

template<> struct Members<MDEntries_m33> {
    using type = Pack<
        Member<decltype(&MDEntries_m33::_MDEntryPx), &MDEntries_m33::_MDEntryPx>,
        Member<decltype(&MDEntries_m33::_MDEntrySize), &MDEntries_m33::_MDEntrySize>,
        Member<decltype(&MDEntries_m33::_SecurityID), &MDEntries_m33::_SecurityID>,
        Member<decltype(&MDEntries_m33::_RptSeq), &MDEntries_m33::_RptSeq>,
        Member<decltype(&MDEntries_m33::_TradingReferenceDate), &MDEntries_m33::_TradingReferenceDate>,
        Member<decltype(&MDEntries_m33::_SettlPriceType), &MDEntries_m33::_SettlPriceType>,
        Member<decltype(&MDEntries_m33::_MDUpdateAction), &MDEntries_m33::_MDUpdateAction>,
        Member<decltype(&MDEntries_m33::_MDEntryType), &MDEntries_m33::_MDEntryType>
    >;
    static const char **names() {
        static const char *rv[] = { "_MDEntryPx", "_MDEntrySize", "_SecurityID", "_RptSeq", "_TradingReferenceDate", "_SettlPriceType", "_MDUpdateAction", "_MDEntryType" };
        return rv;
    }
    static const char *name() { return "MDEntries_m33"; }
};

template<> struct Members<MDIncrementalRefreshDailyStatistics> {
    using type = Pack<
        Member<decltype(&MDIncrementalRefreshDailyStatistics::_TransactTime), &MDIncrementalRefreshDailyStatistics::_TransactTime>,
        Member<decltype(&MDIncrementalRefreshDailyStatistics::_MatchEventIndicator), &MDIncrementalRefreshDailyStatistics::_MatchEventIndicator>
    >;
    static const char **names() {
        static const char *rv[] = { "_TransactTime", "_MatchEventIndicator" };
        return rv;
    }
    static const char *name() { return "MDIncrementalRefreshDailyStatistics"; }
};

template<> struct Members<MDEntries_m34> {
    using type = Pack<
        Member<decltype(&MDEntries_m34::_HighLimitPrice), &MDEntries_m34::_HighLimitPrice>,
        Member<decltype(&MDEntries_m34::_LowLimitPrice), &MDEntries_m34::_LowLimitPrice>,
        Member<decltype(&MDEntries_m34::_MaxPriceVariation), &MDEntries_m34::_MaxPriceVariation>,
        Member<decltype(&MDEntries_m34::_SecurityID), &MDEntries_m34::_SecurityID>,
        Member<decltype(&MDEntries_m34::_RptSeq), &MDEntries_m34::_RptSeq>
    >;
    static const char **names() {
        static const char *rv[] = { "_HighLimitPrice", "_LowLimitPrice", "_MaxPriceVariation", "_SecurityID", "_RptSeq" };
        return rv;
    }
    static const char *name() { return "MDEntries_m34"; }
};

template<> struct Members<MDIncrementalRefreshLimitsBanding> {
    using type = Pack<
        Member<decltype(&MDIncrementalRefreshLimitsBanding::_TransactTime), &MDIncrementalRefreshLimitsBanding::_TransactTime>,
        Member<decltype(&MDIncrementalRefreshLimitsBanding::_MatchEventIndicator), &MDIncrementalRefreshLimitsBanding::_MatchEventIndicator>
    >;
    static const char **names() {
        static const char *rv[] = { "_TransactTime", "_MatchEventIndicator" };
        return rv;
    }
    static const char *name() { return "MDIncrementalRefreshLimitsBanding"; }
};

template<> struct Members<MDEntries_m35> {
    using type = Pack<
        Member<decltype(&MDEntries_m35::_MDEntryPx), &MDEntries_m35::_MDEntryPx>,
        Member<decltype(&MDEntries_m35::_SecurityID), &MDEntries_m35::_SecurityID>,
        Member<decltype(&MDEntries_m35::_RptSeq), &MDEntries_m35::_RptSeq>,
        Member<decltype(&MDEntries_m35::_OpenCloseSettlFlag), &MDEntries_m35::_OpenCloseSettlFlag>,
        Member<decltype(&MDEntries_m35::_MDUpdateAction), &MDEntries_m35::_MDUpdateAction>,
        Member<decltype(&MDEntries_m35::_MDEntryType), &MDEntries_m35::_MDEntryType>
    >;
    static const char **names() {
        static const char *rv[] = { "_MDEntryPx", "_SecurityID", "_RptSeq", "_OpenCloseSettlFlag", "_MDUpdateAction", "_MDEntryType" };
        return rv;
    }
    static const char *name() { return "MDEntries_m35"; }
};

template<> struct Members<MDIncrementalRefreshSessionStatistics> {
    using type = Pack<
        Member<decltype(&MDIncrementalRefreshSessionStatistics::_TransactTime), &MDIncrementalRefreshSessionStatistics::_TransactTime>,
        Member<decltype(&MDIncrementalRefreshSessionStatistics::_MatchEventIndicator), &MDIncrementalRefreshSessionStatistics::_MatchEventIndicator>
    >;
    static const char **names() {
        static const char *rv[] = { "_TransactTime", "_MatchEventIndicator" };
        return rv;
    }
    static const char *name() { return "MDIncrementalRefreshSessionStatistics"; }
};

template<> struct Members<MDEntries_m36> {
    using type = Pack<
        Member<decltype(&MDEntries_m36::_MDEntryPx), &MDEntries_m36::_MDEntryPx>,
        Member<decltype(&MDEntries_m36::_MDEntrySize), &MDEntries_m36::_MDEntrySize>,
        Member<decltype(&MDEntries_m36::_SecurityID), &MDEntries_m36::_SecurityID>,
        Member<decltype(&MDEntries_m36::_RptSeq), &MDEntries_m36::_RptSeq>,
        Member<decltype(&MDEntries_m36::_NumberOfOrders), &MDEntries_m36::_NumberOfOrders>,
        Member<decltype(&MDEntries_m36::_TradeID), &MDEntries_m36::_TradeID>,
        Member<decltype(&MDEntries_m36::_AggressorSide), &MDEntries_m36::_AggressorSide>,
        Member<decltype(&MDEntries_m36::_MDUpdateAction), &MDEntries_m36::_MDUpdateAction>
    >;
    static const char **names() {
        static const char *rv[] = { "_MDEntryPx", "_MDEntrySize", "_SecurityID", "_RptSeq", "_NumberOfOrders", "_TradeID", "_AggressorSide", "_MDUpdateAction" };
        return rv;
    }
    static const char *name() { return "MDEntries_m36"; }
};

template<> struct Members<MDIncrementalRefreshTrade> {
    using type = Pack<
        Member<decltype(&MDIncrementalRefreshTrade::_TransactTime), &MDIncrementalRefreshTrade::_TransactTime>,
        Member<decltype(&MDIncrementalRefreshTrade::_MatchEventIndicator), &MDIncrementalRefreshTrade::_MatchEventIndicator>
    >;
    static const char **names() {
        static const char *rv[] = { "_TransactTime", "_MatchEventIndicator" };
        return rv;
    }
    static const char *name() { return "MDIncrementalRefreshTrade"; }
};

template<> struct Members<MDEntries_m37> {
    using type = Pack<
        Member<decltype(&MDEntries_m37::_MDEntrySize), &MDEntries_m37::_MDEntrySize>,
        Member<decltype(&MDEntries_m37::_SecurityID), &MDEntries_m37::_SecurityID>,
        Member<decltype(&MDEntries_m37::_RptSeq), &MDEntries_m37::_RptSeq>,
        Member<decltype(&MDEntries_m37::_MDUpdateAction), &MDEntries_m37::_MDUpdateAction>
    >;
    static const char **names() {
        static const char *rv[] = { "_MDEntrySize", "_SecurityID", "_RptSeq", "_MDUpdateAction" };
        return rv;
    }
    static const char *name() { return "MDEntries_m37"; }
};

template<> struct Members<MDIncrementalRefreshVolume> {
    using type = Pack<
        Member<decltype(&MDIncrementalRefreshVolume::_TransactTime), &MDIncrementalRefreshVolume::_TransactTime>,
        Member<decltype(&MDIncrementalRefreshVolume::_MatchEventIndicator), &MDIncrementalRefreshVolume::_MatchEventIndicator>
    >;
    static const char **names() {
        static const char *rv[] = { "_TransactTime", "_MatchEventIndicator" };
        return rv;
    }
    static const char *name() { return "MDIncrementalRefreshVolume"; }
};

template<> struct Members<MDEntries_m38> {
    using type = Pack<
        Member<decltype(&MDEntries_m38::_MDEntryPx), &MDEntries_m38::_MDEntryPx>,
        Member<decltype(&MDEntries_m38::_MDEntrySize), &MDEntries_m38::_MDEntrySize>,
        Member<decltype(&MDEntries_m38::_NumberOfOrders), &MDEntries_m38::_NumberOfOrders>,
        Member<decltype(&MDEntries_m38::_MDPriceLevel), &MDEntries_m38::_MDPriceLevel>,
        Member<decltype(&MDEntries_m38::_TradingReferenceDate), &MDEntries_m38::_TradingReferenceDate>,
        Member<decltype(&MDEntries_m38::_OpenCloseSettlFlag), &MDEntries_m38::_OpenCloseSettlFlag>,
        Member<decltype(&MDEntries_m38::_SettlPriceType), &MDEntries_m38::_SettlPriceType>,
        Member<decltype(&MDEntries_m38::_MDEntryType), &MDEntries_m38::_MDEntryType>
    >;
    static const char **names() {
        static const char *rv[] = { "_MDEntryPx", "_MDEntrySize", "_NumberOfOrders", "_MDPriceLevel", "_TradingReferenceDate", "_OpenCloseSettlFlag", "_SettlPriceType", "_MDEntryType" };
        return rv;
    }
    static const char *name() { return "MDEntries_m38"; }
};

template<> struct Members<SnapshotFullRefresh> {
    using type = Pack<
        Member<decltype(&SnapshotFullRefresh::_LastMsgSeqNumProcessed), &SnapshotFullRefresh::_LastMsgSeqNumProcessed>,
        Member<decltype(&SnapshotFullRefresh::_TotNumReports), &SnapshotFullRefresh::_TotNumReports>,
        Member<decltype(&SnapshotFullRefresh::_SecurityID), &SnapshotFullRefresh::_SecurityID>,
        Member<decltype(&SnapshotFullRefresh::_RptSeq), &SnapshotFullRefresh::_RptSeq>,
        Member<decltype(&SnapshotFullRefresh::_TransactTime), &SnapshotFullRefresh::_TransactTime>,
        Member<decltype(&SnapshotFullRefresh::_LastUpdateTime), &SnapshotFullRefresh::_LastUpdateTime>,
        Member<decltype(&SnapshotFullRefresh::_TradeDate), &SnapshotFullRefresh::_TradeDate>,
        Member<decltype(&SnapshotFullRefresh::_MDSecurityTradingStatus), &SnapshotFullRefresh::_MDSecurityTradingStatus>,
        Member<decltype(&SnapshotFullRefresh::_HighLimitPrice), &SnapshotFullRefresh::_HighLimitPrice>,
        Member<decltype(&SnapshotFullRefresh::_LowLimitPrice), &SnapshotFullRefresh::_LowLimitPrice>,
        Member<decltype(&SnapshotFullRefresh::_MaxPriceVariation), &SnapshotFullRefresh::_MaxPriceVariation>
    >;
    static const char **names() {
        static const char *rv[] = { "_LastMsgSeqNumProcessed", "_TotNumReports", "_SecurityID", "_RptSeq", "_TransactTime", "_LastUpdateTime", "_TradeDate", "_MDSecurityTradingStatus", "_HighLimitPrice", "_LowLimitPrice", "_MaxPriceVariation" };
        return rv;
    }
    static const char *name() { return "SnapshotFullRefresh"; }
};

template<> struct Members<RelatedSym_m39> {
    using type = Pack<
        Member<decltype(&RelatedSym_m39::_Symbol), &RelatedSym_m39::_Symbol>,
        Member<decltype(&RelatedSym_m39::_SecurityID), &RelatedSym_m39::_SecurityID>,
        Member<decltype(&RelatedSym_m39::_OrderQty), &RelatedSym_m39::_OrderQty>,
        Member<decltype(&RelatedSym_m39::_QuoteType), &RelatedSym_m39::_QuoteType>,
        Member<decltype(&RelatedSym_m39::_Side), &RelatedSym_m39::_Side>
    >;
    static const char **names() {
        static const char *rv[] = { "_Symbol", "_SecurityID", "_OrderQty", "_QuoteType", "_Side" };
        return rv;
    }
    static const char *name() { return "RelatedSym_m39"; }
};

template<> struct Members<QuoteRequest> {
    using type = Pack<
        Member<decltype(&QuoteRequest::_TransactTime), &QuoteRequest::_TransactTime>,
        Member<decltype(&QuoteRequest::_QuoteReqID), &QuoteRequest::_QuoteReqID>,
        Member<decltype(&QuoteRequest::_MatchEventIndicator), &QuoteRequest::_MatchEventIndicator>
    >;
    static const char **names() {
        static const char *rv[] = { "_TransactTime", "_QuoteReqID", "_MatchEventIndicator" };
        return rv;
    }
    static const char *name() { return "QuoteRequest"; }
};

template<> struct Members<Events_m41> {
    using type = Pack<
        Member<decltype(&Events_m41::_EventType), &Events_m41::_EventType>,
        Member<decltype(&Events_m41::_EventTime), &Events_m41::_EventTime>
    >;
    static const char **names() {
        static const char *rv[] = { "_EventType", "_EventTime" };
        return rv;
    }
    static const char *name() { return "Events_m41"; }
};

template<> struct Members<MDFeedTypes_m41> {
    using type = Pack<
        Member<decltype(&MDFeedTypes_m41::_MDFeedType), &MDFeedTypes_m41::_MDFeedType>,
        Member<decltype(&MDFeedTypes_m41::_MarketDepth), &MDFeedTypes_m41::_MarketDepth>
    >;
    static const char **names() {
        static const char *rv[] = { "_MDFeedType", "_MarketDepth" };
        return rv;
    }
    static const char *name() { return "MDFeedTypes_m41"; }
};

template<> struct Members<InstAttrib_m41> {
    using type = Pack<
        Member<decltype(&InstAttrib_m41::_InstAttribValue), &InstAttrib_m41::_InstAttribValue>
    >;
    static const char **names() {
        static const char *rv[] = { "_InstAttribValue" };
        return rv;
    }
    static const char *name() { return "InstAttrib_m41"; }
};

template<> struct Members<LotTypeRules_m41> {
    using type = Pack<
        Member<decltype(&LotTypeRules_m41::_LotType), &LotTypeRules_m41::_LotType>,
        Member<decltype(&LotTypeRules_m41::_MinLotSize), &LotTypeRules_m41::_MinLotSize>
    >;
    static const char **names() {
        static const char *rv[] = { "_LotType", "_MinLotSize" };
        return rv;
    }
    static const char *name() { return "LotTypeRules_m41"; }
};

template<> struct Members<Underlyings_m41> {
    using type = Pack<
        Member<decltype(&Underlyings_m41::_UnderlyingSecurityID), &Underlyings_m41::_UnderlyingSecurityID>,
        Member<decltype(&Underlyings_m41::_UnderlyingSymbol), &Underlyings_m41::_UnderlyingSymbol>
    >;
    static const char **names() {
        static const char *rv[] = { "_UnderlyingSecurityID", "_UnderlyingSymbol" };
        return rv;
    }
    static const char *name() { return "Underlyings_m41"; }
};

template<> struct Members<MDInstrumentDefinitionOption> {
    using type = Pack<
        Member<decltype(&MDInstrumentDefinitionOption::_MatchEventIndicator), &MDInstrumentDefinitionOption::_MatchEventIndicator>,
        Member<decltype(&MDInstrumentDefinitionOption::_TotNumReports), &MDInstrumentDefinitionOption::_TotNumReports>,
        Member<decltype(&MDInstrumentDefinitionOption::_SecurityUpdateAction), &MDInstrumentDefinitionOption::_SecurityUpdateAction>,
        Member<decltype(&MDInstrumentDefinitionOption::_LastUpdateTime), &MDInstrumentDefinitionOption::_LastUpdateTime>,
        Member<decltype(&MDInstrumentDefinitionOption::_MDSecurityTradingStatus), &MDInstrumentDefinitionOption::_MDSecurityTradingStatus>,
        Member<decltype(&MDInstrumentDefinitionOption::_ApplID), &MDInstrumentDefinitionOption::_ApplID>,
        Member<decltype(&MDInstrumentDefinitionOption::_MarketSegmentID), &MDInstrumentDefinitionOption::_MarketSegmentID>,
        Member<decltype(&MDInstrumentDefinitionOption::_UnderlyingProduct), &MDInstrumentDefinitionOption::_UnderlyingProduct>,
        Member<decltype(&MDInstrumentDefinitionOption::_SecurityExchange), &MDInstrumentDefinitionOption::_SecurityExchange>,
        Member<decltype(&MDInstrumentDefinitionOption::_SecurityGroup), &MDInstrumentDefinitionOption::_SecurityGroup>,
        Member<decltype(&MDInstrumentDefinitionOption::_Asset), &MDInstrumentDefinitionOption::_Asset>,
        Member<decltype(&MDInstrumentDefinitionOption::_Symbol), &MDInstrumentDefinitionOption::_Symbol>,
        Member<decltype(&MDInstrumentDefinitionOption::_SecurityID), &MDInstrumentDefinitionOption::_SecurityID>,
        Member<decltype(&MDInstrumentDefinitionOption::_SecurityType), &MDInstrumentDefinitionOption::_SecurityType>,
        Member<decltype(&MDInstrumentDefinitionOption::_CFICode), &MDInstrumentDefinitionOption::_CFICode>,
        Member<decltype(&MDInstrumentDefinitionOption::_PutOrCall), &MDInstrumentDefinitionOption::_PutOrCall>,
        Member<decltype(&MDInstrumentDefinitionOption::_MaturityMonthYear), &MDInstrumentDefinitionOption::_MaturityMonthYear>,
        Member<decltype(&MDInstrumentDefinitionOption::_Currency), &MDInstrumentDefinitionOption::_Currency>,
        Member<decltype(&MDInstrumentDefinitionOption::_StrikePrice), &MDInstrumentDefinitionOption::_StrikePrice>,
        Member<decltype(&MDInstrumentDefinitionOption::_StrikeCurrency), &MDInstrumentDefinitionOption::_StrikeCurrency>,
        Member<decltype(&MDInstrumentDefinitionOption::_SettlCurrency), &MDInstrumentDefinitionOption::_SettlCurrency>,
        Member<decltype(&MDInstrumentDefinitionOption::_MinCabPrice), &MDInstrumentDefinitionOption::_MinCabPrice>,
        Member<decltype(&MDInstrumentDefinitionOption::_MatchAlgorithm), &MDInstrumentDefinitionOption::_MatchAlgorithm>,
        Member<decltype(&MDInstrumentDefinitionOption::_MinTradeVol), &MDInstrumentDefinitionOption::_MinTradeVol>,
        Member<decltype(&MDInstrumentDefinitionOption::_MaxTradeVol), &MDInstrumentDefinitionOption::_MaxTradeVol>,
        Member<decltype(&MDInstrumentDefinitionOption::_MinPriceIncrement), &MDInstrumentDefinitionOption::_MinPriceIncrement>,
        Member<decltype(&MDInstrumentDefinitionOption::_MinPriceIncrementAmount), &MDInstrumentDefinitionOption::_MinPriceIncrementAmount>,
        Member<decltype(&MDInstrumentDefinitionOption::_DisplayFactor), &MDInstrumentDefinitionOption::_DisplayFactor>,
        Member<decltype(&MDInstrumentDefinitionOption::_TickRule), &MDInstrumentDefinitionOption::_TickRule>,
        Member<decltype(&MDInstrumentDefinitionOption::_MainFraction), &MDInstrumentDefinitionOption::_MainFraction>,
        Member<decltype(&MDInstrumentDefinitionOption::_SubFraction), &MDInstrumentDefinitionOption::_SubFraction>,
        Member<decltype(&MDInstrumentDefinitionOption::_PriceDisplayFormat), &MDInstrumentDefinitionOption::_PriceDisplayFormat>,
        Member<decltype(&MDInstrumentDefinitionOption::_UnitOfMeasure), &MDInstrumentDefinitionOption::_UnitOfMeasure>,
        Member<decltype(&MDInstrumentDefinitionOption::_UnitOfMeasureQty), &MDInstrumentDefinitionOption::_UnitOfMeasureQty>,
        Member<decltype(&MDInstrumentDefinitionOption::_TradingReferencePrice), &MDInstrumentDefinitionOption::_TradingReferencePrice>,
        Member<decltype(&MDInstrumentDefinitionOption::_SettlPriceType), &MDInstrumentDefinitionOption::_SettlPriceType>,
        Member<decltype(&MDInstrumentDefinitionOption::_ClearedVolume), &MDInstrumentDefinitionOption::_ClearedVolume>,
        Member<decltype(&MDInstrumentDefinitionOption::_OpenInterestQty), &MDInstrumentDefinitionOption::_OpenInterestQty>,
        Member<decltype(&MDInstrumentDefinitionOption::_LowLimitPrice), &MDInstrumentDefinitionOption::_LowLimitPrice>,
        Member<decltype(&MDInstrumentDefinitionOption::_HighLimitPrice), &MDInstrumentDefinitionOption::_HighLimitPrice>,
        Member<decltype(&MDInstrumentDefinitionOption::_UserDefinedInstrument), &MDInstrumentDefinitionOption::_UserDefinedInstrument>,
        Member<decltype(&MDInstrumentDefinitionOption::_TradingReferenceDate), &MDInstrumentDefinitionOption::_TradingReferenceDate>
    >;
    static const char **names() {
        static const char *rv[] = { "_MatchEventIndicator", "_TotNumReports", "_SecurityUpdateAction", "_LastUpdateTime", "_MDSecurityTradingStatus", "_ApplID", "_MarketSegmentID", "_UnderlyingProduct", "_SecurityExchange", "_SecurityGroup", "_Asset", "_Symbol", "_SecurityID", "_SecurityType", "_CFICode", "_PutOrCall", "_MaturityMonthYear", "_Currency", "_StrikePrice", "_StrikeCurrency", "_SettlCurrency", "_MinCabPrice", "_MatchAlgorithm", "_MinTradeVol", "_MaxTradeVol", "_MinPriceIncrement", "_MinPriceIncrementAmount", "_DisplayFactor", "_TickRule", "_MainFraction", "_SubFraction", "_PriceDisplayFormat", "_UnitOfMeasure", "_UnitOfMeasureQty", "_TradingReferencePrice", "_SettlPriceType", "_ClearedVolume", "_OpenInterestQty", "_LowLimitPrice", "_HighLimitPrice", "_UserDefinedInstrument", "_TradingReferenceDate" };
        return rv;
    }
    static const char *name() { return "MDInstrumentDefinitionOption"; }
};

template<> struct Members<MDEntries_m42> {
    using type = Pack<
        Member<decltype(&MDEntries_m42::_MDEntryPx), &MDEntries_m42::_MDEntryPx>,
        Member<decltype(&MDEntries_m42::_MDEntrySize), &MDEntries_m42::_MDEntrySize>,
        Member<decltype(&MDEntries_m42::_SecurityID), &MDEntries_m42::_SecurityID>,
        Member<decltype(&MDEntries_m42::_RptSeq), &MDEntries_m42::_RptSeq>,
        Member<decltype(&MDEntries_m42::_NumberOfOrders), &MDEntries_m42::_NumberOfOrders>,
        Member<decltype(&MDEntries_m42::_AggressorSide), &MDEntries_m42::_AggressorSide>,
        Member<decltype(&MDEntries_m42::_MDUpdateAction), &MDEntries_m42::_MDUpdateAction>
    >;
    static const char **names() {
        static const char *rv[] = { "_MDEntryPx", "_MDEntrySize", "_SecurityID", "_RptSeq", "_NumberOfOrders", "_AggressorSide", "_MDUpdateAction" };
        return rv;
    }
    static const char *name() { return "MDEntries_m42"; }
};

template<> struct Members<OrderIDEntries_m42> {
    using type = Pack<
        Member<decltype(&OrderIDEntries_m42::_OrderID), &OrderIDEntries_m42::_OrderID>,
        Member<decltype(&OrderIDEntries_m42::_LastQty), &OrderIDEntries_m42::_LastQty>
    >;
    static const char **names() {
        static const char *rv[] = { "_OrderID", "_LastQty" };
        return rv;
    }
    static const char *name() { return "OrderIDEntries_m42"; }
};

template<> struct Members<MDIncrementalRefreshTradeSummary> {
    using type = Pack<
        Member<decltype(&MDIncrementalRefreshTradeSummary::_TransactTime), &MDIncrementalRefreshTradeSummary::_TransactTime>,
        Member<decltype(&MDIncrementalRefreshTradeSummary::_MatchEventIndicator), &MDIncrementalRefreshTradeSummary::_MatchEventIndicator>
    >;
    static const char **names() {
        static const char *rv[] = { "_TransactTime", "_MatchEventIndicator" };
        return rv;
    }
    static const char *name() { return "MDIncrementalRefreshTradeSummary"; }
};

}
#define PP_SEQ_MDP3_DecimalQty (mantissa)
#define PP_SEQ_MDP3_FLOAT (mantissa)
#define PP_SEQ_MDP3_MaturityMonthYear (year)(month)(day)(week)
#define PP_SEQ_MDP3_PRICE (mantissa)
#define PP_SEQ_MDP3_PRICENULL (mantissa)
#define PP_SEQ_MDP3_groupSize (blockLength)(numInGroup)
#define PP_SEQ_MDP3_groupSize8Byte (blockLength)(numInGroup)
#define PP_SEQ_MDP3_groupSizeEncoding (blockLength)(numInGroup)
#define PP_SEQ_MDP3_messageHeader (blockLength)(templateId)(schemaId)(version)
#define PP_SEQ_MDP3_MDEntries_m4 (_ApplID)
#define PP_SEQ_MDP3_ChannelReset (_TransactTime)(_MatchEventIndicator)
#define PP_SEQ_MDP3_AdminHeartbeat 
#define PP_SEQ_MDP3_AdminLogin (_HeartBtInt)
#define PP_SEQ_MDP3_AdminLogout (_Text)
#define PP_SEQ_MDP3_Events_m27 (_EventType)(_EventTime)
#define PP_SEQ_MDP3_MDFeedTypes_m27 (_MDFeedType)(_MarketDepth)
#define PP_SEQ_MDP3_InstAttrib_m27 (_InstAttribValue)
#define PP_SEQ_MDP3_LotTypeRules_m27 (_LotType)(_MinLotSize)
#define PP_SEQ_MDP3_MDInstrumentDefinitionFuture (_MatchEventIndicator)(_TotNumReports)(_SecurityUpdateAction)(_LastUpdateTime)(_MDSecurityTradingStatus)(_ApplID)(_MarketSegmentID)(_UnderlyingProduct)(_SecurityExchange)(_SecurityGroup)(_Asset)(_Symbol)(_SecurityID)(_SecurityType)(_CFICode)(_MaturityMonthYear)(_Currency)(_SettlCurrency)(_MatchAlgorithm)(_MinTradeVol)(_MaxTradeVol)(_MinPriceIncrement)(_DisplayFactor)(_MainFraction)(_SubFraction)(_PriceDisplayFormat)(_UnitOfMeasure)(_UnitOfMeasureQty)(_TradingReferencePrice)(_SettlPriceType)(_OpenInterestQty)(_ClearedVolume)(_HighLimitPrice)(_LowLimitPrice)(_MaxPriceVariation)(_DecayQuantity)(_DecayStartDate)(_OriginalContractSize)(_ContractMultiplier)(_ContractMultiplierUnit)(_FlowScheduleType)(_MinPriceIncrementAmount)(_UserDefinedInstrument)(_TradingReferenceDate)
#define PP_SEQ_MDP3_Events_m29 (_EventType)(_EventTime)
#define PP_SEQ_MDP3_MDFeedTypes_m29 (_MDFeedType)(_MarketDepth)
#define PP_SEQ_MDP3_InstAttrib_m29 (_InstAttribValue)
#define PP_SEQ_MDP3_LotTypeRules_m29 (_LotType)(_MinLotSize)
#define PP_SEQ_MDP3_Legs_m29 (_LegSecurityID)(_LegSide)(_LegRatioQty)(_LegPrice)(_LegOptionDelta)
#define PP_SEQ_MDP3_MDInstrumentDefinitionSpread (_MatchEventIndicator)(_TotNumReports)(_SecurityUpdateAction)(_LastUpdateTime)(_MDSecurityTradingStatus)(_ApplID)(_MarketSegmentID)(_UnderlyingProduct)(_SecurityExchange)(_SecurityGroup)(_Asset)(_Symbol)(_SecurityID)(_SecurityType)(_CFICode)(_MaturityMonthYear)(_Currency)(_SecuritySubType)(_UserDefinedInstrument)(_MatchAlgorithm)(_MinTradeVol)(_MaxTradeVol)(_MinPriceIncrement)(_DisplayFactor)(_PriceDisplayFormat)(_PriceRatio)(_TickRule)(_UnitOfMeasure)(_TradingReferencePrice)(_SettlPriceType)(_OpenInterestQty)(_ClearedVolume)(_HighLimitPrice)(_LowLimitPrice)(_MaxPriceVariation)(_MainFraction)(_SubFraction)(_TradingReferenceDate)
#define PP_SEQ_MDP3_SecurityStatus (_TransactTime)(_SecurityGroup)(_Asset)(_SecurityID)(_TradeDate)(_MatchEventIndicator)(_SecurityTradingStatus)(_HaltReason)(_SecurityTradingEvent)
#define PP_SEQ_MDP3_MDEntries_m32 (_MDEntryPx)(_MDEntrySize)(_SecurityID)(_RptSeq)(_NumberOfOrders)(_MDPriceLevel)(_MDUpdateAction)(_MDEntryType)
#define PP_SEQ_MDP3_MDIncrementalRefreshBook (_TransactTime)(_MatchEventIndicator)
#define PP_SEQ_MDP3_MDEntries_m33 (_MDEntryPx)(_MDEntrySize)(_SecurityID)(_RptSeq)(_TradingReferenceDate)(_SettlPriceType)(_MDUpdateAction)(_MDEntryType)
#define PP_SEQ_MDP3_MDIncrementalRefreshDailyStatistics (_TransactTime)(_MatchEventIndicator)
#define PP_SEQ_MDP3_MDEntries_m34 (_HighLimitPrice)(_LowLimitPrice)(_MaxPriceVariation)(_SecurityID)(_RptSeq)
#define PP_SEQ_MDP3_MDIncrementalRefreshLimitsBanding (_TransactTime)(_MatchEventIndicator)
#define PP_SEQ_MDP3_MDEntries_m35 (_MDEntryPx)(_SecurityID)(_RptSeq)(_OpenCloseSettlFlag)(_MDUpdateAction)(_MDEntryType)
#define PP_SEQ_MDP3_MDIncrementalRefreshSessionStatistics (_TransactTime)(_MatchEventIndicator)
#define PP_SEQ_MDP3_MDEntries_m36 (_MDEntryPx)(_MDEntrySize)(_SecurityID)(_RptSeq)(_NumberOfOrders)(_TradeID)(_AggressorSide)(_MDUpdateAction)
#define PP_SEQ_MDP3_MDIncrementalRefreshTrade (_TransactTime)(_MatchEventIndicator)
#define PP_SEQ_MDP3_MDEntries_m37 (_MDEntrySize)(_SecurityID)(_RptSeq)(_MDUpdateAction)
#define PP_SEQ_MDP3_MDIncrementalRefreshVolume (_TransactTime)(_MatchEventIndicator)
#define PP_SEQ_MDP3_MDEntries_m38 (_MDEntryPx)(_MDEntrySize)(_NumberOfOrders)(_MDPriceLevel)(_TradingReferenceDate)(_OpenCloseSettlFlag)(_SettlPriceType)(_MDEntryType)
#define PP_SEQ_MDP3_SnapshotFullRefresh (_LastMsgSeqNumProcessed)(_TotNumReports)(_SecurityID)(_RptSeq)(_TransactTime)(_LastUpdateTime)(_TradeDate)(_MDSecurityTradingStatus)(_HighLimitPrice)(_LowLimitPrice)(_MaxPriceVariation)
#define PP_SEQ_MDP3_RelatedSym_m39 (_Symbol)(_SecurityID)(_OrderQty)(_QuoteType)(_Side)
#define PP_SEQ_MDP3_QuoteRequest (_TransactTime)(_QuoteReqID)(_MatchEventIndicator)
#define PP_SEQ_MDP3_Events_m41 (_EventType)(_EventTime)
#define PP_SEQ_MDP3_MDFeedTypes_m41 (_MDFeedType)(_MarketDepth)
#define PP_SEQ_MDP3_InstAttrib_m41 (_InstAttribValue)
#define PP_SEQ_MDP3_LotTypeRules_m41 (_LotType)(_MinLotSize)
#define PP_SEQ_MDP3_Underlyings_m41 (_UnderlyingSecurityID)(_UnderlyingSymbol)
#define PP_SEQ_MDP3_MDInstrumentDefinitionOption (_MatchEventIndicator)(_TotNumReports)(_SecurityUpdateAction)(_LastUpdateTime)(_MDSecurityTradingStatus)(_ApplID)(_MarketSegmentID)(_UnderlyingProduct)(_SecurityExchange)(_SecurityGroup)(_Asset)(_Symbol)(_SecurityID)(_SecurityType)(_CFICode)(_PutOrCall)(_MaturityMonthYear)(_Currency)(_StrikePrice)(_StrikeCurrency)(_SettlCurrency)(_MinCabPrice)(_MatchAlgorithm)(_MinTradeVol)(_MaxTradeVol)(_MinPriceIncrement)(_MinPriceIncrementAmount)(_DisplayFactor)(_TickRule)(_MainFraction)(_SubFraction)(_PriceDisplayFormat)(_UnitOfMeasure)(_UnitOfMeasureQty)(_TradingReferencePrice)(_SettlPriceType)(_ClearedVolume)(_OpenInterestQty)(_LowLimitPrice)(_HighLimitPrice)(_UserDefinedInstrument)(_TradingReferenceDate)
#define PP_SEQ_MDP3_MDEntries_m42 (_MDEntryPx)(_MDEntrySize)(_SecurityID)(_RptSeq)(_NumberOfOrders)(_AggressorSide)(_MDUpdateAction)
#define PP_SEQ_MDP3_OrderIDEntries_m42 (_OrderID)(_LastQty)
#define PP_SEQ_MDP3_MDIncrementalRefreshTradeSummary (_TransactTime)(_MatchEventIndicator)

#define PP_SEQ_MDP3_CATEGORY_composite (DecimalQty)(FLOAT)(MaturityMonthYear)(PRICE)(PRICENULL)(groupSize)(groupSize8Byte)(groupSizeEncoding)(messageHeader)
#define PP_SEQ_MDP3_CATEGORY_Message (ChannelReset)(AdminHeartbeat)(AdminLogin)(AdminLogout)(MDInstrumentDefinitionFuture)(MDInstrumentDefinitionSpread)(SecurityStatus)(MDIncrementalRefreshBook)(MDIncrementalRefreshDailyStatistics)(MDIncrementalRefreshLimitsBanding)(MDIncrementalRefreshSessionStatistics)(MDIncrementalRefreshTrade)(MDIncrementalRefreshVolume)(SnapshotFullRefresh)(QuoteRequest)(MDInstrumentDefinitionOption)(MDIncrementalRefreshTradeSummary)
#define PP_SEQ_MDP3_CATEGORY_RepeatingGroup (MDEntries_m4)(Events_m27)(MDFeedTypes_m27)(InstAttrib_m27)(LotTypeRules_m27)(Events_m29)(MDFeedTypes_m29)(InstAttrib_m29)(LotTypeRules_m29)(Legs_m29)(MDEntries_m32)(MDEntries_m33)(MDEntries_m34)(MDEntries_m35)(MDEntries_m36)(MDEntries_m37)(MDEntries_m38)(RelatedSym_m39)(Events_m41)(MDFeedTypes_m41)(InstAttrib_m41)(LotTypeRules_m41)(Underlyings_m41)(MDEntries_m42)(OrderIDEntries_m42)
