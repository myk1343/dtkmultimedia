// SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later

#include "mockdemo/mockdemo.h"
#include "gtest/gtest.h"
#include "3rdparty/cpp-stub/src/stub.h"
#include <DMediaMetaData>
#include "dtkmultimedia.h"

DMULTIMEDIA_USE_NAMESPACE

class ut_DMediaMetaData : public testing::Test
{
public:
    void SetUp() override
    {
        m_mediaMetaData = new DMediaMetaData;
    }
    void TearDown() override
    {
        delete m_mediaMetaData;
        m_mediaMetaData = nullptr;
    }
public:
    DMediaMetaData *m_mediaMetaData = nullptr;
};

TEST_F(ut_DMediaMetaData, value)
{
    m_mediaMetaData->insert(DMediaMetaData::Title, "test");
    EXPECT_EQ("test", m_mediaMetaData->value(DMediaMetaData::Title));
}

TEST_F(ut_DMediaMetaData, insert)
{
    m_mediaMetaData->insert(DMediaMetaData::Author, "test");
}

TEST_F(ut_DMediaMetaData, remove)
{
    m_mediaMetaData->insert(DMediaMetaData::Author, "test");
    m_mediaMetaData->remove(DMediaMetaData::Author);
}

TEST_F(ut_DMediaMetaData, keys)
{
    m_mediaMetaData->insert(DMediaMetaData::Comment, "test");
    EXPECT_EQ(QList<DMediaMetaData::Key>() << DMediaMetaData::Comment, m_mediaMetaData->keys());
}

TEST_F(ut_DMediaMetaData, key_operation)
{
    m_mediaMetaData->insert(DMediaMetaData::Description, "test");
    m_mediaMetaData[DMediaMetaData::Description];
    DMediaMetaData meta1, meta2;
    meta1.insert(DMediaMetaData::Description, "test");
    meta2.insert(DMediaMetaData::Description, "test");
    ASSERT_EQ(meta1, meta2);
    meta1.insert(DMediaMetaData::Comment, "test");
    ASSERT_NE(meta1, meta2);
}

TEST_F(ut_DMediaMetaData, clear)
{
    m_mediaMetaData->clear();
}

TEST_F(ut_DMediaMetaData, isEmpty)
{
    m_mediaMetaData->isEmpty();
}

TEST_F(ut_DMediaMetaData, stringValue)
{
    m_mediaMetaData->insert(DMediaMetaData::Language, "test");
    EXPECT_EQ("", m_mediaMetaData->stringValue(DMediaMetaData::Language));
}

TEST_F(ut_DMediaMetaData, metaDataKeyToString)
{
    m_mediaMetaData->metaDataKeyToString(DMediaMetaData::Language);
}
